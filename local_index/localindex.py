#!/usr/bin/python
# -*- coding: utf-8 -*-

import MonitorListener
import Filter
from xml.etree import ElementTree
from time import time

if __name__=="__main__":
	ml=MonitorListener.MonitorListener()
	nl=ml.getlistazasobow()
	ml.startServer()
	while (len(nl)<1):
		pass
	query="""<Search name="update" id="0" >
		<timestamp value="%d" />
	</Search>""" % (int(time()-3),)
	print "zapytanie:"
	print query
	tree=ElementTree.fromstring(query)
	query=tree.getchildren()[0]
	print Filter.FilterByTimestamp().filter(query,nl.poProstuDajListe())
	print "\n\n"
	query="""<Search name="request_001" id="12345">
     <Filters>
          <Filter name="CPU-Frequency" />
          <Filter name="MEM-Count" />
          <Filter name="OS-Name" />
     </Filters>
     <Data>
	<Compare type="AND">
          <Atrybute name="MEM-Count" compType="&gt;" value="64kB" />
	  <Atrybute name="OS-Name" compType="==" value="Debian 6 (Squeeze)" />
	</Compare>
     </Data>
	</Search>"""
	print "zapytanie:"
	print query
	#wybieram z zapytania tylko galaz Data
	tree=ElementTree.fromstring(query)
	query=tree.getchildren()[1]
	print Filter.FilterByQuery().filter(query,nl.poProstuDajListe())
	ml.stopServer()