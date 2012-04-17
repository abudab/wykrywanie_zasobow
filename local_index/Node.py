#!/usr/bin/python
# -*- coding: utf-8 -*-

class Node:
	"""Pojedyńczy zasób, czyli zbiór informacji otrzymanych z jednego monitora.
	Na razie wykorzystuje zwykły słownik,
	"""
	node={}
	def setParam(self,param,value):
		self.node[param]=value
	def deleteParam(self,param):
		del self.node[param]
	def getValue(self,param):
		return self.node[param]
	def getParams(self):
		return self.node.keys()

if __name__=="__main__":
	a=Node()
	a.setParam('CPU','PicoBlaze')
	a.setParam('freq','50MHz')
	for i in a.getParams():
		print a.getValue(i)
	a.deleteParam('CPU')
	for i in a.getParams():
		print a.getValue(i)