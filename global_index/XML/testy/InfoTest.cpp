#include <iostream>


using namespace std;
#include "XML/info.h"
#include <vector>


int main()
{
    int ok=0;
    int failed=0;
    //konstruktor domyślny
    Info in;
    string na="non";
    cout<<"Kontruktor domyślny ->";
    if(in.getType()==na)
       {
        ++ok;
        cout<<"OK"<<endl;
       }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    string nazwa="nowa";
    //konatruktor od string
    cout<<"Konstruktor zależny od string ->";
    Info in2(nazwa);
    if(in2.getType()==nazwa)
    {
        ++ok;
        cout<<"OK"<<endl;
       }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<"Zmiana typu ->";
    //nadanie typu
    in.setType(na);
    if(in.getType()==na)
   {
        ++ok;
        cout<<"OK"<<endl;
       }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    //kopia
    cout<<"Kopiowanie do innego obiektu tej klasy ->";
    in.Copy(in2);
    if(in.getType()==in2.getType())
      {
        ++ok;
        cout<<"OK"<<endl;
       }
    else
    {
        ++failed;
        cout<<"FAIL"<<endl;
    }
    cout<<endl;
    cout<<"Przeprowadzono "<<ok+failed<<" testów, gdzie:"<<endl<<ok<<" pomyślnie zakończonych"<<endl<<failed<<" zakończonych niepowodzeniem";
    cout<<endl;
    return 0;
}

