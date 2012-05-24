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
	    string xml("<?xml version='1.0' ?> <Search name='request_001' id='12345'><Filters><Filter name='CPU-Frequency' /><Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters><Data><Compare type='OR'><Compare type='AND'><Atrybute name='CPU-frequency' compType='>=' value='1.0GHz' /><Atrybute name='CPU-frequency' compType='<=' value='2.0GHz' /></Compare><Atrybute name='MEM-Count' compType='>=' value='4GB' /></Compare></Data></Search>");
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
        cout<<"ustawienie nowych filtrów -> ";
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
	    //szuka2.loadS(xml);
	    if(szuka2.getName()!=""&&szuka2.getIdI()>0)
	    {
	        ++ok;
	        cout<<"OK";
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
                int rr=vc2[i]->getInfo().size();
                cout<<"\t type: "<<vc2[i]->getType()<<" , rozmiar: "<<rr<<endl;
                 for(int j=0;j<rr;++j)
                {
                    Compare* cc=new Compare();
                    Atribute* ati=new Atribute();
                    if(dynamic_cast<Compare*>(vc2[i]->getInfo()[j]))
                    {
                        cc=(dynamic_cast<Compare*>(vc2[i]->getInfo()[j]))->Copy();
                        int r2=cc->getInfo().size();
                        cout<<"\t\t Porownanie: "<<cc->getType()<<" , rozmiar: "<<r2<<endl;
                       for(int k=0;k<r2;++k)
                        {
                            Compare* cc1=new Compare();
                            Atribute* at1=new Atribute();
                            if(dynamic_cast<Compare*>(cc->getInfo()[k]))
                            {
                                cc1=(dynamic_cast<Compare*>(cc->getInfo()[k]))->Copy();
                                cout<<"\t\t\t Porownanie: "<<cc1->getType()<<" , rozmiar: "<<cc1->getInfo().size()<<endl;
                                delete cc1;
                            }
                            else
                            {
                                if(dynamic_cast<Atribute*>(cc->getInfo()[k]))
                                {
                                    at1=(dynamic_cast<Atribute*>(cc->getInfo()[k]))->Copy();
                                    cout<<"\t\t\t Atrybut: "<<at1->getName()<<" , "<<at1->getType()<<" , "<<at1->getValue()<<endl;
                                    delete at1;
                                }
                                else
                                {
                                    cout<<"FAIL"<<endl;
                                }
                            }


                        }
                        delete cc;

                    }
                    else
                    {
                        if(dynamic_cast<Atribute*>(vc2[i]->getInfo()[j]))
                        {
                            ati=(dynamic_cast<Atribute*>(vc2[i]->getInfo()[j]))->Copy();
                            cout<<"\t\t Atribut: "<<ati->getName()<<" , "<<ati->getType()<<" , "<<ati->getValue()<<endl;
                            delete ati;
                        }
                        else
                        {
                            cout<<"FAIL";
                        }
                    }
                }
            }

	    }
	    else
	    {
	        ++fail;
	        cout<<"NIC"<<endl;
	    }

	    cout<<"Podanie niepoprawnego ciagu "<<endl;
        string inny("<cos></cos>");
        Search s21(inny);
        cout<<s21.getName()<<" , "<<s21.getId()<<" , Porownania: "<<s21.getComp().size()<<" , filtry "<<s21.getFilters().size()<<endl;

        Search s33;
        s33.loadS("");

        cout<<s33.getName()<<" , "<<s33.getId()<<" , Porownania: "<<s33.getComp().size()<<" , filtry "<<s33.getFilters().size()<<endl;

    cout<<endl<<"Przeprowadzono "<<fail+ok<<" testów, gdzie:"<<endl<<"-> Poprawnych: "<<ok<<endl<<"-> Niepoprawnych: "<<fail<<endl;
	    return 0;
	}

