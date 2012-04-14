#!/usr/bin/python
# -*- coding: utf-8 -*-

#DO ZROBIENIA 
#http://docs.python.org/library/socketserver.html
import SocketServer
from NodesListWrapper import NodesListWrapper

nodeslist=NodesListWrapper()

class RequestHandler(SocketServer.BaseRequestHandler):
	def handle(self):
		pass
		#zrobic - patrzy na adres i albo dodaje nowy Node do nodeslist albo
		#	modyfikuje stary

def getNodesList():
	return nodeslist

def startListening():
	tcpserver=SocketServer.TCPServer(('127.0.0.1',5488),RequestHandler)	
	tcpserver.serve_forever()		