#include <iostream>
#include "XML/Monitor.h"
#include <vector>
#include "XML/Response.h"
#include "pugi/pugiconfig.hpp"
#include "pugi/pugixml.hpp"
using namespace std;
//using namespace pugi;
int main()
{
    int ok=0;
    int fail=0;

    cout<<"Konstruktor domyślny: ";
    Response rr;
    if(rr.getId()==0)
    {
        ++ok;
        cout<<"->OK, mamy odpowiedz o id = "<<rr.getId()<<"i ilosci monitorow: "<<rr.getMonitor().size()<<endl;

    }
    else
    {
        ++fail;
        cout<<"-> FAIL"<<endl;
    }
    Atribute* at=new Atribute();
	vector<Atribute*> k;
	k.push_back(at);
	vector<Atribute*> k2;
	cout<<at->getName()<<", "<<at->getValue() << ", "<<at->getType()<<endl;
	Monitor m;
	Monitor m1("mon1",k);
	m1.addAtrib(at);
	cout<<m.getName()<<endl;
	cout<<m1.getName()<<endl;
	    m.addAtrib(at);
	m.addAtrib(at);
     //   k2.C(m.getAtrib());
	m.addAtrib(at);
	at->setName("Frequency");
	m.addAtrib(at);


cout<<"Dodanie monitora ";
	rr.addMonitor(&m);
	if(rr.getMonitor().size()>0)
	{
	    ++ok;
	    int k=rr.getMonitor().size();
	    cout<<"-> OK => ilosci monitorow: "<<k<<endl;
	    for(int i=0;i<k;++i)
        cout<<"monitor "<<rr.getMonitor()[i]->getName()<<" ma "<<rr.getMonitor()[i]->getAtrib().size()<<"Atrybuty"<<endl;

	}
	else{ ++fail;
    cout<<"FAIL"<<endl;
	}
	rr.addMonitor(&m);
	rr.addMonitor(&m1);
	rr.getMonitor().size();
	cout<<"Pobranie wektora monitorow:";
	vector<Monitor*> mov=rr.getMonitor();
	if(mov.size()==rr.getMonitor().size())
	{
	    cout<<"->OK"<<endl;
	    ++ok;
	}
	else
	{
	    ++fail;
	    cout<<"FAIL"<<endl;
	}
	int r=mov.size();
	cout<<"Konstruktor on int i wektora monitorów";
	Response rr1(3,mov);
	if(rr1.getMonitor().size()==r&& rr1.getId()==3)
	{
	    cout<<"-> OK"<<endl;
	    ++ok;
	    for(int i=0;i<r;++i)
        cout<<"Monitor "<<i<<" o nazwie: "<<rr1.getMonitor()[i]->getName()<<" i ilosci Atrybutow"<<rr1.getMonitor()[i]->getAtrib().size()<<endl;
    int ra=rr1.getMonitor()[0]->getAtrib().size();
    cout<<"Monitor 0 ma "<<ra<<" atrybutów, kolejno:"<<endl;
    for(int i=0; i<ra;++i)
    cout<<"\t\t"<<rr1.getMonitor()[0]->getAtrib()[i]->getName()<<" typ: "<<rr1.getMonitor()[0]->getAtrib()[i]->getType()<<" = "<<rr1.getMonitor()[0]->getAtrib()[i]->getValue()<<endl;
	}
	else
	{
	    ++fail;
	    cout<<"-> FAIL"<<endl;
	}

cout<<"Zapis klasy w postaci XML:";
string klasa=rr.toXML();
if(klasa!="")
{
    ++ok;
    cout<<"->OK, mamy XML:"<<endl;
    cout<<klasa<<endl;
}
else
{
    ++fail;
    cout<<"FAIL"<<endl;
}

    cout <<endl<< "Przeprowadzono " <<ok+fail<<" testów:"<<endl<<"-> poprawnie dziala:"<<ok<<endl<<"->niepoprawnie zadzialało w "<<fail<<" testach."<<endl;

    return 0;
}

