#include <iostream>


using namespace std;
#include "XML/Atribute.h"
#include <vector>


int main()
{
    //Dwa rodzaje konstruktorów
    Atribute at;
    Atribute at2("CPU", "cc","8");

    cout<<at.getName()<<", "<<at.getValue() << ", "<<at.getType()<<endl;
    cout<<at2.getName()<<", "<<at2.getValue() << ", "<<at2.getType()<<endl;

    //zmiana wartości Value poprzez string
    at.setValue("6");
    //urzycie value jako int
    int w= at.getValueI() + at2.getValueI();
    cout<<w<<endl;
    //nadanie nowej nazwy
    at.setName("new_name");
    //nadanie nowej wartości
    at.setValue(300);
    //nadanie nowego typu
    at.setType("new_type");
    cout<<at.getName()<<", "<<at.getValue() << ", "<<at.getType()<<endl;
    //kopiowanie
    at.Copy(at2);
    at2.setName("inne");
    cout<<at.getName()<<", "<<at.getValue() << ", "<<at.getType()<<endl;
    cout<<at2.getName()<<", "<<at2.getValue() << ", "<<at2.getType()<<endl;
    return 0;
}

