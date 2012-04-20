#include <iostream>
using namespace std;
#include "XML/Atribute.h"
#include "XML/Monitor.h"
#include <vector>
int main()
{
    int failed=0;
    int ok=0;
    string s2("na"), s3("cc"),s4("34");
    Atribute* at=new Atribute(s2,s3,s4);
    vector<Atribute*> k;
    k.push_back(at);
    vector<Atribute*> k2;
    cout<<"Konstruktor domyślny-> ";
    Monitor m;
    if(m.getName()!="")
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<"Konstruktor od stringa i wektora atrybutów -> ";
    string s1="mon1";
    Monitor m1(s1,k);
    if(s1==m1.getName()&&!k.empty())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<"Zmiana nazwy monitora -> ";
    s1="monit2";
    m.setName(s1);
    if(s1==m.getName())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<"Dodanie atrybutu ->";
    m1.addAtrib(at);
    m1.addAtrib(at);
    m1.addAtrib(at);
    if(m1.getAtrib().size()==4)
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }


    k2=(m.getAtrib());
    m.addAtrib(at);
    at->setName("nnn");
    m.addAtrib(at);
    int r=m.getAtrib().size();
    cout<<"Zmiana wektora atrybutow -> ";
    m.setAtribs(k2);
    if(m.getAtrib().size()!=r&&m.getAtrib().size()==k2.size())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    r=m.getAtrib().size();
    cout<<"Kopiowanie Monitora -> ";
    m.Copy(m1);
    if(m.getName()==m1.getName()&&m.getAtrib().size()!=r&&m.getAtrib().size()==m1.getAtrib().size())
    {
        ++ok;
        cout<<"OK"<<endl;
    }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<"Kopia i oryginał mają swoje, rózne wersje obiektow -> ";
    m.getAtrib()[0]->setName(s3);
    if(m.getAtrib()[0]->getName()==s3 && m.getAtrib()[0]->getName()!=m1.getAtrib()[0]->getName())
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
