#!/usr/bin/python
# -*- coding: utf-8 -*-

import MonitorListener
import Filter
from xml.etree import ElementTree
from time import time
from RestfulServer import *

if __name__=="__main__":
	ml=MonitorListener.MonitorListener()
	nl=ml.getlistazasobow()
	ml.startServer()

	srv = RestfulServer()
	srv.addHandler(DefaultHandler)
  	srv.addHandler(QueryHandler)
	srv.addHandler(TimestampHandler)
  	srv.setNodesList(nl)
  	srv.startServer()
	
