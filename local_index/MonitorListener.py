#!/usr/bin/python
# -*- coding: utf-8 -*-

#obsluga polaczenia monitor <-> indeks lokalny
#autor: Mariusz Stefanski

#http://docs.python.org/library/socketserver.html
import SocketServer
from NodesListWrapper import NodesListWrapper
from Node import Node
from xml.etree import ElementTree as xml
from time import time
import threading
   


class MonitorListener:
    
    HOST, PORT = "127.0.0.1", 5488
    #baza - wrapper listy, przechowuje informacje dot. wezlow
    listazasobow=NodesListWrapper()
    
    """
    Uruchamia serwer korzystając z danego numeru HOST i PORT
    """
    def startServer(self):
	    print " [ Rozpoczeto prace aplikacji! ] "
	    self.tcpserver=SocketServer.ThreadingTCPServer((self.HOST,self.PORT),RequestHandler)
	    self.server_thread = threading.Thread(target=self.tcpserver.serve_forever)
	    self.server_thread.start()
	    print " [ Uruchomiono serwer ] "    
	    #tcpserver.serve_forever()
	    #print " [ juz po wszystkim ] "
	    
    def getHost(self):
        return self.HOST
    def getPort(self):
        return self.PORT    
    def getlistazasobow(self):
        return self.listazasobow
    def setNodesList(self, list):
        for i in list:
            self.listazasobow.add(i)
    def stopServer(self):
	try:
		self.tcpserver.shutdown()
	except:
		pass
    """
    Dodaje do listy zasobow Node
    @param lvMonitor: fragment XML z zawartoscia Node'a 
    """
    def __dodajDoListyXML(self,lvMonitor):
        node = Node()
        node.setParam('name', (lvMonitor.attrib['name'], int(time())))
        for lvAtrybute in lvMonitor:
            node.setParam(lvAtrybute.attrib['name'], (lvAtrybute.attrib['value'], int(time())))
        self.listazasobow.add(node)
    
    """
    Uaktualnia dany wezel - dla danego arybutu ustawia nowa wartosc i timestamp
    @param node: nowy wezel
    @param coUaktualnic: lista z nazwami kluczy do uaktualnienia  
    """    
    def uaktualnijNode(self,node, coUaktualnic):
        for i in self.listazasobow.poProstuDajListe():
            if node.getValue('name')[0]==i.getValue('name')[0]:
                for key in coUaktualnic[0]:
                    i.deleteParam(key)
                    i.setParam(key, (node.getValue(key)[0], int(time())))
    """
    Parsuje dany XML i dodaje/uaktualnia liste zasobow
    @param data: string z XMLem 
    """            
    def parsujXML(self,data):
        if data!=None:
            print ' --- [ Parsowanie danych ] --- '
            lvMonitor = xml.fromstring(data)
            nazwaMonitora = lvMonitor.attrib['name']
            
            node = Node()
            node.setParam('name', (lvMonitor.attrib['name'], int(time())))
            for lvAtrybute in lvMonitor:
                node.setParam(lvAtrybute.attrib['name'], (lvAtrybute.attrib['value'], int(time())))
                
                
            #jezeli nie ma nic na liscie - dodajemy bez patrzenia
            if len(self.listazasobow.poProstuDajListe())==0:
                self.listazasobow.add(node)
            #mamy elementy na liscie - sprawdzamy czy jest juz jakis o danym name    
            else:
                czyJestNaLiscie = False
                for i in self.listazasobow.poProstuDajListe():
                    if nazwaMonitora==i.getValue('name')[0]:
                        czyJestNaLiscie = True                     
                        czyUaktualnic = i.isDiffirent(node)
                        break
                if czyJestNaLiscie==False:
                    self.listazasobow.add(node)   
                elif czyUaktualnic[0]:
                    print '   - [ Uaktualniam wezel: '+nazwaMonitora+'] -'
                    self.uaktualnijNode(node, czyUaktualnic[1:])
                else:
                    print '   - [ Wezel: '+nazwaMonitora+' pozostaje bez zmian] -'
                    #uaktualnijElementListy(lvMonitor)
        
        
    """
        Pobiera string z danymi od monitora. Wyswietla baze danych
        
    """
    def obsluzDane(self,data):
        #rozkaz, dane = data.partition(":")[0],data.partition(":")[2]
        
        self.parsujXML(data)
        
        #listazasobow.add(node.setParam(rozkaz, dane))
        iloscPrzeslanych = len(self.listazasobow.poProstuDajListe())
        print " --- [ Dotychczas zapisano elementow: %d" % iloscPrzeslanych + "] ---"
        print " --- [ Lista obiektów zapisanych na liście ] ---"
        a=self.listazasobow.poProstuDajListe()
        for i in a:
            print ' -------- obiekt:'
            j=i.getParams()
            for k in j:
                print ' ----------- '+ k,' - ', i.getValue(k)

class RequestHandler(SocketServer.BaseRequestHandler):
    """
        Klasa - serwer. Przyjmuje zgłoszenia monitora.
    """
    def setup(self):
            print ' [ ',self.client_address, ' - Nastapilo polaczenie ] '

    """
        Reaguje na dane od monitora.
    """
    def handle(self):
        data = self.request.recv(1024)
        monitor =  MonitorListener()
        monitor.obsluzDane(data)
   
    def finish(self):
            print ' [ ',self.client_address, ' - Nastapilo rozlaczenie ] '
        
        #zrobic - patrzy na adres i albo dodaje nowy Node do listazasobow albo
        #    modyfikuje stary

if __name__ == "__main__":
	monitor = MonitorListener()
	monitor.startServer()

            
