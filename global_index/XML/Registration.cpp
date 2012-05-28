#include "Registration.h"
#include "../pugi/pugixml.hpp"
#include <iostream>

using namespace std;
using namespace pugi;


/// Konstruktor domyślny nadaje _address=""
Registration::Registration()
{
    _address="";
}
/// Konstruktor tworzący obiekt klasy z zapytania xml
/// Nie sprawdza czy  podany w xmlu adres jest poprawny
/// \param xml zapytanie XML w postaci string
Registration::Registration(std::string xml)
{
    //utworzenie obiektu dokumentu xml
     xml_document doc;
//wczytanie struktury dokumrntu
    doc.load(xml.c_str());
    //obiekt odnoszący się do noda search
    xml_node search = doc.child("Registration");
    if(search.empty())
    {
        _address="";

    }
    else
    {
      _address=search.attribute("address").value();

        if(_address.empty())
        {
           _address="";
        }

    }

}
