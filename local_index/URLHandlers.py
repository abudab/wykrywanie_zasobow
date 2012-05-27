#!/usr/bin/python
# -*- coding: utf-8 -*-

import web
from xml.etree import ElementTree
from xml.dom.minidom import Document
from Filter import *

class URLHandler:
  __url__ = None
  __server__ = None
  
class DefaultHandler(URLHandler):
  __url__ = "/"
  
  def GET(self):
    return "Foo Bar" 
    
class QueryHandler(URLHandler):
  __url__ = "/query"
  
  def POST(self):
    tree=ElementTree.fromstring(web.data())
    query=tree.getchildren()[1]
    return self.createXMLResp(FilterByQuery().filter(query,self.__server__.getNodesList().poProstuDajListe()))
	
  def createXMLResp(self,resp):
    xml = Document()
    resnode = xml.createElement("Response")
    xml.appendChild(resnode)
    for monitor in resp:
      monnode = xml.createElement("Monitor")
      monnode.setAttribute("name", monitor["name"])
      for k,v in monitor.items():
	if k == "name":
	  continue
	attrnode = xml.createElement("Atrybute")
	attrnode.setAttribute("name", k)
	attrnode.setAttribute("value", v)
	attrnode.setAttribute("type", "Static")
	monnode.appendChild(attrnode)
      resnode.appendChild(monnode)
    return xml.toxml()

class TimestampHandler(URLHandler):
  __url__ = "/update"
  
  def POST(self):
    tree=ElementTree.fromstring(web.data())
    query=tree.getchildren()[0]
    return self.createXMLResp(FilterByTimestamp().filter(query,self.__server__.getNodesList().poProstuDajListe()))
	
  def createXMLResp(self,resp):
    xml = Document()
    resnode = xml.createElement("Response")
    xml.appendChild(resnode)
    for monitor in resp:
      monnode = xml.createElement("Monitor")
      monnode.setAttribute("name", monitor["name"])
      for k,v in monitor.items():
	if k == "name":
	  continue
	attrnode = xml.createElement("Atrybute")
	attrnode.setAttribute("name", k)
	attrnode.setAttribute("value", v)
	attrnode.setAttribute("type", "Static")
	monnode.appendChild(attrnode)
      resnode.appendChild(monnode)
    return xml.toxml()
	
