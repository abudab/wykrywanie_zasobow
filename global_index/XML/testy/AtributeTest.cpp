#include <iostream>
using namespace std;
#include "XML/Atribute.h"
#include <vector>
int main()
{
    int failed=0;
    int ok=0;

    //Dwa rodzaje konstruktorów
    cout<<"Konstruktor domyślny oraz działanie getType(), getValue() i getName()";
    Atribute at;
    if(at.getType()=="non")
{
    cout<<"-> OK:"<<at.getName()<<", "<<at.getValue() << ", "<<at.getType()<<endl;
    ++ok;
}
else
{
    cout<<"-> FAIL";
    ++failed;
}
cout<<"Konstruktor zależny od 3 stringów ->";
string s1("CPU"), s2("ctype"), s3("8");
    Atribute at2(s1,s2,s3);
if(at2.getName()==s1&&at2.getValue()==s3&&at2.getType()==s2)
{
cout<<" OK: ";
    cout<<at2.getName()<<", "<<at2.getValue() << ", "<<at2.getType()<<endl;
    ++ok;
}
else
{
    ++failed;
    cout<<" FAIL"<<endl;
}
    cout<<"zmiana wartości Value poprzez string ->";
    string s4("6");
    at.setValue(s4);
    if(at.getValue()==s4)
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<" FAIL"<<endl;
    }
    int ww=14;

    cout<<"urzycie value jako int -> ";
    int w= at.getValueI() + at2.getValueI();
    if(w==ww)
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    //nadanie nowej nazwy
    s1="new_name";
    cout<<"nadanie nowej nazwy -> ";
    at.setName(s1);
    if(at.getName()==s1)
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    w=300;
    s1="20";
    cout<<"nadanie nowej wartości -> ";
    at.setValue(w);
    at2.setValue(s1);
    if(at2.getValue()==s1&& at.getValueI()==w)
    {
        ++ok;
        cout<<"OK"<<endl;
        ++ok;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
        ++failed;
    }
    cout<<"nadanie nowego typu -> ";
    s1="new_type";
    at.setType(s1);
    if(s1==at.getType())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }

    //kopiowanie
    cout<<"Kopiowanie elementu -> ";
    at.Copy(at2);
    at2.setName("inne");
    if(at.getName()!=at2.getName()&&at.getType()==at2.getType()&&at.getValue()==at2.getValue())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<endl<<"Przeprowadzono "<<failed+ok<<" testów, gdzie:"<<endl<<"-> Poprawnych: "<<ok<<endl<<"-> Niepoprawnych: "<<failed<<endl;
    return 0;
}

