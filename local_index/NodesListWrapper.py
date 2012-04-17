#!/usr/bin/python
# -*- coding: utf-8 -*-

class NodesListWrapper:
	"""Klasa enkapsuluje listę węzłów (znaczy komputerów-zasobów).
Na razie wystarczy lista do której wrzuca się obiekty
typu Node. W razie potrzeby można klasę rozbudować, żeby wykorzystywała
bazę danych.  
"""
	zwyklaLista=[]
	def add(self,node):
		self.zwyklaLista.append(node)
	def delete(self,i):
		del self.zwyklaLista[i]
	def get(self,i):
		return self.zwyklaLista[i]
	def __len__(self):
		return len(self.zwyklaLista)
	def poProstuDajListe(self):
		""" Na razie wykorzystywana jest zwykla lista. Metoda zwraca do niej wskaźnik.
		"""
		return self.zwyklaLista
		
if __name__=="__main__":
	a=NodesListWrapper()
	a.add({1:'a',2:'b'})
	print a.get(0)
	b=a.poProstuDajListe()
	b.append(":P")
	print len(a)