#!/usr/bin/python
# -*- coding: utf-8 -*-

#DO ZROBIENIA 

#import MonitorListener
import web #http://webpy.org/docs/0.3/tutorial
from URLHandlers import *
from threading import Thread
from inspect import isclass
from NodesListWrapper import NodesListWrapper as NodesList
from Node import Node


class RestfulHandler(Thread):
  def __init__(self, urls):
    Thread.__init__(self)
    self.m_app = web.application(urls, globals())
  
  def run(self):
    self.m_app.run()

class RestfulServer:
  def __init__(self):
    self.m_nodeslist = None
    self.m_handler = None
    self.m_urlhandlers = []

  def addHandler(self,urlhandler):
    urlhandler.__server__ = self
    self.m_urlhandlers.extend([urlhandler.__url__,urlhandler.__name__])
	
    
  def startServer(self):
    self.m_handler = RestfulHandler(tuple(self.m_urlhandlers))
    self.m_handler.start() 
    
  def setNodesList(self, nodeslist):
    self.m_nodeslist = nodeslist
    
  def getNodesList(self):
    return self.m_nodeslist
    
    
if __name__ == "__main__": 
  osy=('DOS','GNU','Solaris')
  nl=NodesList()
  for i in range(1,11):
		nl.add(Node({ 'name':          ('local_192.168.1.'+str(i) , 0),
	      'CPU-Frequency': (str(i*0.5)+'GHz'          , int(time())-i),
	      'MEM-Count':     (str(1000*i)+'MB'          , int(time())-i-2 ),
	      'OS-Name':       (osy[i%3], 0 )}))
  print nl.poProstuDajListe()
  srv = RestfulServer()
  srv.addHandler(DefaultHandler)
  srv.addHandler(QueryHandler)
  srv.setNodesList(nl)
  srv.startServer()
  
  print('\ndupdupdupa')

