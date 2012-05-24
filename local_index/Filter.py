#!/usr/bin/env python

from xml.etree import ElementTree
from time import time

class Filter:
	"""Abstrakcyjny filtr - klasa z metoda
	filtrujaca przyjmujaca galaz XML - zapytanie + 
	liste zasobow do przefiltrowania"""
	def filter(query,nodeslist):
		pass
		
class FilterByQuery (Filter):
	""" Filtr obslugujacy zapytania POST na domain/local.
	Zgodnie z wzorcowym xml, obsluguje zagniezdzone 
	w OR'ach i AND'ach klasyfikatory: ==,>=,<=,<,>.
	Atrybuty CPU-Frequency i MEM-Count maja jeszcze obsluge
	jednostek: kHz,MHz,GHz, kB,MB,GB (jesli jednostka suffiksem wartosci).
	Wartosci innych atrybutow beda po prostu podstawiane do porownan jak leci."""
	compTypes=(">=","<=","==","<",">")

	def filter(self,query,nodeslist):
		"""Glowna metoda filtrujaca"""
		rl=self.compareOR(query,nodeslist)
		resultlist=[dict([(k,v[0]) for k,v in i.items()]) for i in rl ]
		return resultlist
		
	def compareOR(self,query,nodeslist):
		"""Filtruje wyrazenie OR dodajac
		do listy zwracanej wszystkie niepowtarzajace sie elementy
		wynikow podwyrazen"""
		#print 'OR'
		resultlist=[]
		for i in query.getchildren():
			subresult=[]
			if i.tag=="Compare":
				if i.get('type')=="OR":
					subresult=self.compareOR(i,nodeslist)
				elif i.get('type')=="AND":
					subresult=self.compareAND(i,nodeslist)
			else:
				subresult=self.filterSpecifically(i,nodeslist)
			for new in subresult:
				if new not in resultlist:
					resultlist.append(new)
		#print resultlist
		return resultlist
		
	def compareAND(self,query,nodeslist):
		"""Filtruje wyrazenie AND dodajac do listy
		jedynie wspolne dla podwyrazen wyniki"""
		#print 'AND'
		resultlist=nodeslist
		anythingFiltered=False
		for i in query.getchildren():
			if i.tag=="Compare":
				if i.get('type')=="OR":
					resultlist=self.compareOR(i,resultlist)
					anythingFiltered=True
				elif i.get('type')=="AND":
					resultlist=self.compareAND(i,resultlist)
					anythingFiltered=True
			else:
				resultlist=self.filterSpecifically(i,resultlist)
				anythingFiltered=True
		#print resultlist
		return resultlist
		
	def filterSpecifically(self,query,nodeslist):
		"""Filtruje z konkretnym wyrazeniem: atrybut.wartosc ? prog
		"""
		#print 'spec'
		resultlist=[]
		try:
			name=query.get('name')
			compType=query.get('compType')
			value=query.get('value')
			value=self.absoluteValue(name,value)
			if compType not in self.compTypes: raise
			for i in nodeslist:
				if name in i:
					ival=self.absoluteValue(name,i[name][0])
					if eval(repr(ival)+compType+repr(value)):
						resultlist.append(i)
		except:
			pass
		return resultlist
			
	def absoluteValue(self,name,value):
		"""Przelicza wartosci wymagajace specjalnego traktowania na ich
		wartosc bezwzglegna. np ilosc pamieci, gdy konczy sie na MB zostanie przeliczona
		na bajty i pozbawiona suffixa.
		"""
		if name not in ('MEM-Count','CPU-Frequency'): 
			return value
		mem={'kB':lambda a:float(a)*1024,'MB':lambda a:float(a)*1024*1024,'GB':lambda a:float(a)*1024*1024*1024}
		frq={'kHz':lambda a:float(a)*1000,'MHz':lambda a:float(a)*1e6,'GHz':lambda a:float(a)*1e9}
		if name=='MEM-Count':
			for suffix in mem:
				if value.endswith(suffix):
					return mem[suffix](value[:value.index(suffix)])
		else:
			for suffix in frq:
				if value.endswith(suffix):
					return frq[suffix](value[:value.index(suffix)])
		return value
		
class FilterByTimestamp(Filter):
	def filter(self,query,nodeslist):
		resultlist=[]
		try:
			timestamp=int(query.get('value'))
			for i in nodeslist:
				d={}
				for (k,v) in i.items():
					if v[1]>=timestamp:
						d[k]=v[0];
				if d: 
					d['name']=i['name'][0]
					resultlist.append(d)
		except:
			pass
		return resultlist
		
			
			
# test/sposob wykorzystania:
if __name__=="__main__":
	#przykladowa lista zasobow
	osy=('DOS','GNU','Solaris')
	#lista to lista slownikow, z podwojnymi wartosciami: atrybut->(wartosc,timestamp)
	nl=[{ 'name':          ('local_192.168.1.'+str(i) , 0),
	      'CPU-Frequency': (str(i*0.5)+'GHz'          , int(time())-i),
	      'MEM-Count':     (str(1000*i)+'MB'          , int(time())-i-2 ),
	      'OS-Name':       (osy[i%3], 0 )} for i in range(1,11)]
	#przykladowe zapytanie (prosto z wiki)
	query="""<Search name="request_001" id="12345">
     <Filters>
          <Filter name="CPU-Frequency" />
          <Filter name="MEM-Count" />
          <Filter name="OS-Name" />
     </Filters>
     <Data>
	<Compare type="AND">
          <Compare type="OR">
               <Compare type="AND">
                    <Atrybute name="CPU-Frequency" compType="&gt;=" value="1.0GHz" />
                    <Atrybute name="CPU-Frequency" compType="&lt;=" value="2.0GHz" />
               </Compare>
               <Atrybute name="MEM-Count" compType="&gt;=" value="4GB" />
          </Compare>
	  <Atrybute name="OS-Name" compType="==" value="Solaris" />
	</Compare>
     </Data>
	</Search>"""
	#wybieram z zapytania tylko galaz Data
	tree=ElementTree.fromstring(query)
	query=tree.getchildren()[1]
	print FilterByQuery().filter(query,nl)
	
	
	#filtrowanie przez czas zmiany
	query="""<Search name="update" id="0" >
		<timestamp value="%d" />
	</Search>""" % (int(time()-3),)
	#print nl
	#print query
	
	tree=ElementTree.fromstring(query)
	query=tree.getchildren()[0]
	print FilterByTimestamp().filter(query,nl)
		