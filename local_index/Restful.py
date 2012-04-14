#!/usr/bin/python
# -*- coding: utf-8 -*-

#DO ZROBIENIA 

import MonitorListener
import web #http://webpy.org/docs/0.3/tutorial

class Pong:
	#zrobić obsługa GET/POST albo obu,
	#na razie może zwracać zawartość MonitorListener.getNodesList()

urls={'/ping','Pong'}

app=web.application(urls,globals())

