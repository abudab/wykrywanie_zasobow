#include <iostream>
	using namespace std;
	#include "XML/Atribute.h"
	#include <vector>
	int main()
	{
	    //Dwa rodzaje konstruktorów
	    int ok=0;
	    int fail=0;
	    cout<<"TESTY KLASY ATRIBUTE"<<endl<<endl;
	    cout<<"Konstruktor domyślny ->";
	    Atribute at;
	    if(at.getName()!="")
	    {
	        ++ok;
	        cout<<"OK"<<endl<<"Atrybut o wartosciach: "<<at.getName()<<", "<<at.getValue() << ", "<<at.getType()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;

	    }
	    cout<<"Konstruktor od 3 stringow ->";
	    string s1("CPU"), s2("cc"), s3("8");
	    Atribute at2(s1, s2,s3);
	    if(at2.getName()==s1&&at2.getType()==s2&&at2.getValue()==s3)
	    {
	        ++ok;
	        cout<<"OK"<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }

	    cout<<"zmiana wartości Value poprzez string-> ";
	    string s4("6");
	    at.setValue(s4);
	    if(at.getValue()==s4)
	    {
	        ++ok;
	        cout<<"OK"<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }
	    cout<<"urzycie value jako int ->";
	    int w= at.getValueI() + at2.getValueI();
	    if(w==14)
	    {
	        ++ok;
	        cout<<"OK"<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }
	    cout<<"nadanie nowej nazwy ->";
	    string s5("naowa_nazwa");
	    at.setName(s5);
	    if(s5==at.getName())
	    {

	        ++ok;
	        cout<<"OK"<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }
	    cout<<"nadanie nowej wartości za pomocą int->";
	    int val=300;
	    at.setValue(val);
	    if(at.getValueI()==val)
	    {

	        ++ok;
	        cout<<"OK"<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }
	    cout<<"nadanie nowego typu->";
	    string s6("new_type");
	    at.setType(s6);
	    if(s6==at.getType())
	    {
	        ++ok;
	        cout<<"OK"<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }

	    cout<<"kopiowanie ->";
	    at.Copy(at2);
	    if((at.getName()==at2.getName())||(at.getType()==at2.getType()) || (at.getValue()==at2.getValue()))
	    {
	        ++ok;
	        cout<<"OK"<<endl;
	        at2.setName("inne");
	        if(at2.getName()!=at.getName())
	        {
	            ++ok;
	            cout<<"sa to 2 niezalezne obiekty"<<endl;
	        }
	        else
	        {
	            ++fail;
	            cout<<"obiekty zaleza od siebie"<<endl;
	        }
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }
	    cout<<"Konstruktor kopiujacy ->";
	    Atribute at3(at);

	     if(at.getName()==at3.getName()&&at.getType()==at3.getType()&&at.getValue()==at3.getValue())
	    {
	        ++ok;
	        cout<<"OK"<<endl;
	        at3.setName("sys");
	        if(at3.getName()!=at.getName())
	        {
	            ++ok;
	            cout<<"sa to 2 niezalezne obiekty"<<endl;
	        }
	        else
	        {
	            ++fail;
	            cout<<"obiekty zaleza od siebie"<<endl;
	        }
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL"<<endl;
	    }
	    cout<<"\n\n Przeprowadzono "<<fail+ok<<"testow:"<<"\n gdzie pomyślnie klasa przeszła: "<<ok<<"\n a niepomyślnie: "<<fail<<endl;
	    return 0;
	}

