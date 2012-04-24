#include <iostream>
	#include <typeinfo>
	#include "pugi/pugiconfig.hpp"
	#include "pugi/pugixml.hpp"
	using namespace std;
	//#include "XML/Monitor.h"
	#include <vector>
	#include "XML/Response.h"
	#include "XML/Search.h"
	//
	//using namespace pugi;
	int main()
	{
	    int ok=0;
	    int fail=0;
	    string xml("<Search name='request_001' id='12345'><Filters><Filter name='CPU-Frequency' /><Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters><Data><Compare type='OR'><Compare type='AND'><Atrybute name='CPUfrequency' compType='>=' value='1.0GHz' /><Compare type='xxx'><Atrybute name='CPUfrequency' compType='<=' value='2.0GHz' /></Compare><Atrybute name='CPUfrequency' compType='<=' value='2.0GHz' /></Compare><Atrybute name='MEMCount' compType='>=' value='4GB' /></Compare></Data></Search>");
	    cout<<"Konstruktor domyslny -> ";
	    Search sz;
	    if(sz.getName()!="")
	    {
	        ++ok;
	        cout<<"OK :"<<sz.getName()<<","<<sz.getId()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
	    Search szuka;
		string s1("szukam");
		cout<<"Nadanie nazwy -> ";
		szuka.setName(s1);
		if(s1==szuka.getName())
		{
	        ++ok;
	        cout<<"OK :"<<sz.getName()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
		int id_n=60;
		cout<<"Nadanie nowej wartości id -> ";
		szuka.setId(id_n);
		if(szuka.getIdI()==id_n)
		{
	        ++ok;
	        cout<<"OK :"<<szuka.getId()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL "<<szuka.getId()<<endl;

	    }
	    Atribute* at=new Atribute();
        vector<Atribute*> k;
        k.push_back(at);
        vector<Atribute> k2;
	    Monitor m;

		Monitor m1("mon1",k);
		m1.addAtrib(at);
        m.addAtrib(at);
		m.addAtrib(at);
		m.addAtrib(at);
		at->setName("nnn");
		m.addAtrib(at);
        Response rr;
		rr.addMonitor(&m);
		rr.addMonitor(&m);
		rr.addMonitor(&m1);
		vector<Monitor*> mov=rr.getMonitor();
		Response rr1(3,mov);
		int r=mov.size();
		Compare c;
		    c.addInfo(at);
		    at->setType("xxx");
		    c.addInfo(at);
		    vector<Info*> n=c.getInfo();
		     r=n.size();
		 Compare c2;
		    c2.Copy(c);
		    c2.addInfo(at);
		    c2.addInfo(&c);
        int siz=szuka.getComp().size();
        cout<<"Dodanie porównania -> ";
        szuka.addCompare(&c2);

        if(szuka.getComp().size()>siz)
        {
	        ++ok;
	        cout<<"OK "<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
		szuka.addCompare(&c);

		string* napis=new string("napis");
		siz=szuka.getFilters().size();
		cout<<"Dodanie filtra -> ";
		szuka.addFilter(napis);
		if(szuka.getFilters().size()>siz)
		{
	        ++ok;
	        cout<<"OK "<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
	    //setCompare
	    vector<Compare* > c_vec;
	    c_vec.push_back(&c);
	    c_vec.push_back(&c2);
	    c_vec.push_back(&c);
	    c_vec.push_back(&c);
	    c_vec.push_back(&c2);
        siz=szuka.getComp().size();
        cout<<"Wstawienie nowego wektora porównań -> ";
        szuka.setCompare(c_vec);
        if(szuka.getComp().size()!=siz)
        {
	        ++ok;
	        cout<<"OK "<<endl;
	    }
	    else
	    {

	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
	    //setFilters
        vector<string*> fil_v;
        siz=szuka.getFilters().size();
        cout<<"ustawienie niwych filtrów -> ";
        szuka.setFilters(fil_v);
        if(siz!=szuka.getFilters().size())
        {
	        ++ok;
	        cout<<"OK "<<endl;
	    }
	    else
	    {

	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
	    cout<<"Konstruktor zależny od striga zawierającego XMLa -> ";
	    Search szuka2(xml);
	    if(szuka2.getName()!=""&&szuka2.getIdI()>0)
	    {
	        ++ok;
	        cout<<endl<<"  --> utworzony obiekt o nazwie:"<<szuka2.getName()<<" i id: "<<szuka2.getId()<<endl;
            cout<<"  --> z filtrami:"<<endl;
            vector<string*> vs=szuka2.getFilters();
            r=vs.size();
            for(int i=0;i<r;++i)
            {
            string ns=(*vs[i]);
            cout<<"         "<<ns<<endl;
            }
            cout<<"  --> z ";

            vector<Compare*> vc2=szuka2.getComp();
            cout<<vc2.size()<<" elementami porównawczymi:"<<endl;
            r=vc2.size();
            for(int i=0;i<r;++i)
            {
                cout<<"           type: "<<vc2[i]->getType()<<" ,"<<vc2[i]->getInfo().size()<<":"<<endl;

                for(int j=0;j<vc2[i]->getInfo().size();++j)
                {
                Atribute* ati=(Atribute*)(vc2[i]->getInfo()[j]);
                cout<<"                 ->"<<ati->getName()<<", "<<ati->getValue()<<endl;
                }
                cout<<endl;


            }

	    }
	    else
	    {
	        ++fail;
	        cout<<"NIC"<<endl;
	    }

    cout<<endl<<"Przeprowadzono "<<fail+ok<<" testów, gdzie:"<<endl<<"-> Poprawnych: "<<ok<<endl<<"-> Niepoprawnych: "<<fail<<endl;
	    return 0;
	}

