#include <iostream>
	#include <typeinfo>
	#include "pugi/pugiconfig.hpp"
	#include "pugi/pugixml.hpp"
	using namespace std;
	//#include "XML/Monitor.h"
	#include <vector>
	#include "XML/Response.h"
	#include "XML/Search.h"
int main()
{
    int ok=0;
    int fail=0;
    cout<<"\nTEST KLASY COMPARE\n";
    cout<<"Konstruktor domyślny ->";
    Compare c1;
    if(c1.getType()!=""&&c1.getInfo().size()==0)
    {
        ++ok;
        cout<<"OK \n\t\t Utworzono porownanie "<<c1.getType()<<" o "<<c1.getInfo().size()<<" informacjach"<<endl;
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
    string s1("OR");
    cout<<"Konstruktor od 1 stringa ->";
    Compare c2(s1);
    if(s1==c2.getType())
    {
        ++ok;
        cout<<"OK \n\t\t Utworzono porownanie "<<c2.getType()<<" o "<<c2.getInfo().size()<<" informacjach"<<endl;
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
    vector<Info*> vec;
    Atribute at1("at1","==","3");
    Atribute at2("at2","<","7");
    cout<<"Dodanie Atrybutu do wektora informacji ->";
    c2.addInfo((&at1));
    if(c2.getInfo().size()==1)
    {
        Atribute* ati=(Atribute*)(c2.getInfo()[0]);
        if((ati)->getName()==at1.getName()&&ati->getType()==at1.getType()&&ati->getValue()==at1.getValue())
        {
            ++ok;
            cout<<"OK"<<endl;
        }
        else
        {
            ++fail;
            cout<<"FAIL"<<endl;
        }
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
    c2.addInfo((&at2));
    vec.push_back(&at1);
    vec.push_back(&at2);
    vec.push_back(&c2);
    int r=vec.size();
    /*
    for(int i=0;i<r;++i)
    {
        if(i<2)
        {
            Atribute* ati=(Atribute*)vec[i];
            cout<<ati->getName()<<" , "<<ati->getValue()<<" , "<<ati->getType()<<endl;
        }
        else
        {
            Compare* com=(Compare*)vec[i];
            int roz=com->getInfo().size();
            cout<<com->getType()<<" ma: "<<roz<<" informacji"<<endl;
            for(int j=0;j<roz;++j)
            {
                Atribute* ati=(Atribute*)(com->getInfo()[j]);
                cout<<"\t info "<<j<<" zawiera Atrybut:"<<ati->getName()<<" , "<<ati->getType()<<" , "<<ati->getValue()<<endl;
            }

        }
    }*/
    cout<<"Dodanie Compare do Info ->";
    c1.addInfo(&c2);
    if(c1.getInfo().size()==1)
    {
        Compare* com=(Compare*)(c1.getInfo()[0]);
        int roz=com->getInfo().size();
        if(roz>0)
        {
            ++ok;
            cout<<"OK"<<endl;
            for(int i=0;i<roz;++i)
            {
                Atribute* ati=(Atribute*)(com->getInfo()[i]);
                cout<<"\t\tAtribute: "<<ati->getName()<<" , "<<ati->getType()<<" , "<<ati->getValue()<<endl;
            }
        }
        else
        {
            ++fail;
            cout<<"FAIL"<<endl;
        }
    }
     else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
    Compare c5;
    cout<<"Funkcja kopiująca ->";
    c5.Copy(c1);
    if(c1.getType()==c5.getType()&&c1.getInfo().size()==c5.getInfo().size())
    {
        cout<<"OK"<<endl;
        ++ok;
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
   cout<<"Nadanie informacji w postaci wektora ->";
    c1.setInfo(vec);
    if(c1.getInfo().size()==vec.size())
    {
        ++ok;
        int roz=c1.getInfo().size();
        cout<<"Ok"<<endl;
        cout<<"\tCompare "<<c1.getType()<<" zawiera "<<roz<<" informacji:"<<endl;

        for(int i=0;i<roz;++i)
        {
            if(i<2)
            {
                Atribute* ati=(Atribute*)c1.getInfo()[i];
                cout<<"\t\t"<<ati->getName()<<" , "<<ati->getValue()<<" , "<<ati->getType()<<endl;
            }
            else
            {
                Compare* com=(Compare*)c1.getInfo()[i];
                int roz=com->getInfo().size();
                cout<<"\t\t"<<com->getType()<<" ma: "<<roz<<" informacji"<<endl;
                for(int j=0;j<roz;++j)
                {
                    Atribute* ati=(Atribute*)(com->getInfo()[j]);
                    cout<<"\t\t\t info "<<j<<" zawiera Atrybut:"<<ati->getName()<<" , "<<ati->getType()<<" , "<<ati->getValue()<<endl;
                }

            }

        }
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
    cout<<"Konstruktor kopiujący ->";
    Compare c3(c2);
    if(c2.getType()==c3.getType()&&c2.getInfo().size()==c3.getInfo().size())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }
    cout<<"Konstruktor od 1 string i wektora Info ->";
    Compare c4("AND", vec);
    if(c4.getInfo().size()==vec.size())
    {
        ++ok;
        cout<<"OK"<<endl;
        int roz=c4.getInfo().size();
        cout<<"\tCompare "<<c4.getType()<<" zawiera "<<roz<<" informacji:"<<endl;

        for(int i=0;i<roz;++i)
        {
            if(i<2)
            {
                Atribute* ati=(Atribute*)c4.getInfo()[i];
                cout<<"\t\t"<<ati->getName()<<" , "<<ati->getValue()<<" , "<<ati->getType()<<endl;
            }
            else
            {
                Compare* com=(Compare*)c4.getInfo()[i];
                int roz=com->getInfo().size();
                cout<<"\t\t"<<com->getType()<<" ma: "<<roz<<" informacji"<<endl;
                for(int j=0;j<roz;++j)
                {
                    Atribute* ati=(Atribute*)(com->getInfo()[j]);
                    cout<<"\t\t\t info "<<j<<" zawiera Atrybut:"<<ati->getName()<<" , "<<ati->getType()<<" , "<<ati->getValue()<<endl;
                }

            }

        }
    }
    else
    {
        ++fail;
        cout<<"FAIL"<<endl;
    }

    cout<<"\n\nPrzprowadzono "<<ok+fail<<" testów:"<<"\n\t -> poprawnie wykonanych: "<<ok<<"\n\t -> niepoprawnie wykonanych: "<<fail<<endl;

    return 0;
}

