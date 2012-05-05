#!/usr/bin/python
# -*- coding: utf-8 -*-

#DO ZROBIENIA 
#http://docs.python.org/library/socketserver.html
import SocketServer
from NodesListWrapper import NodesListWrapper
from Node import Node
HOST, PORT = "127.0.0.1", 5488
nodeslist=NodesListWrapper()

"""
	Pobiera string z danymi od monitora. Przekazuje do NodesListWrapper
"""
def obsluzDane(data):
	rozkaz, dane = data.partition(":")[0],data.partition(":")[2]
	node = Node()
	nodeslist.add(node.setParam(rozkaz, dane))
	iloscPrzeslanych = len(nodeslist.poProstuDajListe())
	print "Dotychczas przeslano elementow: %d" % iloscPrzeslanych
	

class RequestHandler(SocketServer.BaseRequestHandler):
	"""
		Klasa - serwer. Przyjmuje zgłoszenia monitora.
	"""
	def setup(self):
        	print self.client_address, 'connected!'

	"""
		Reaguje na dane od monitora.
	"""
	def handle(self):
		print "uruchamiam handle!:"
		data = self.request.recv(1024)
		obsluzDane(data)
   
	def finish(self):
        	print self.client_address, 'disconnected!'
        
		#zrobic - patrzy na adres i albo dodaje nowy Node do nodeslist albo
		#	modyfikuje stary


print "Rozpoczeto prace!"
tcpserver=SocketServer.ThreadingTCPServer((HOST,PORT),RequestHandler)
print "Uruchomiono serwer"	
tcpserver.serve_forever()
print "juz po wszystkim"


def getNodesList():
	return nodeslist


			
