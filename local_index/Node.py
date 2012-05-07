#!/usr/bin/python
# -*- coding: utf-8 -*-

class Node(dict):
	"""Pojedyńczy zasób, czyli zbiór informacji otrzymanych z jednego monitora.
	Na razie wykorzystuje zwykły słownik,
	"""
	#def __init__ (self):
	#	self.Node = {}
	def setParam(self,param,value):
		self[param]=value
	def deleteParam(self,param):
		del self[param]
	def getValue(self,param):
		return self[param]
	def getParams(self):
		return self.keys()
	def isDiffirent(self, other):
		coZmienic=[]
		myKeys = self.keys()
		for i in myKeys:
			if other.has_key(i):
				if self[i][0]!=other[i][0]:
					coZmienic.append(i)
			else:
				coZmienic.append(i)
		if len(coZmienic)>0:
			return (True, coZmienic)
		else:
			return (False,[])	

if __name__=="__main__":
	a=Node()
	a.setParam('CPU','PicoBlaze')
	a.setParam('freq','50MHz')
	for i in a.getParams():
		print a.getValue(i)
	a.deleteParam('CPU')
	for i in a.getParams():
		print a.getValue(i)