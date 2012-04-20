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
    if(in.getType()==na)
        ++ok;
    else
        ++failed;
    string nazwa="nowa";
    //konatruktor od string
    Info in2(nazwa);
    if(in2.getType()==nazwa)
        ++ok;
    else
        ++failed;

    //nadanie typu
    in.setType(na);
    if(in.getType()==na)
        ++ok;
    else
        ++failed;
    //kopia
    in.Copy(in2);
    if(in.getType()==in2.getType())
        ++ok;
    else
        ++failed;

    cout<<"Przeprowadzono "<<ok+failed<<" testów, gdzie:"<<endl<<ok<<" pomyślnie zakończonych"<<endl<<failed<<" zakończonych niepowodzeniem";
    return 0;
}

