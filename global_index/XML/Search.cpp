#include "Search.h"
#include "Atribute.h"
#include <sstream>
#include "../pugi/pugixml.hpp"
//#include "../pugi/pugiconfig.hpp"
#include <iostream>

using namespace std;
using namespace pugi;
///Konstruktor domyslny klasy Search nadaje _name="non" i _id=0
Search::Search():_name("non"), _id(0)
{
    vector<Compare*> w;
    _comp=w;
    vector<string*> s;
    _filters=s;

}
/// Konstruktor tworzący obiekt klasy search z zapytania xml
/// \param xml zapytanie XML w postaci string
Search::Search(string xml)
{

//utworzenie obiektu dokumentu xml
     xml_document doc;
//wczytanie struktury dokumrntu
    doc.load(xml.c_str());
    //obiekt odnoszący się do noda search
    xml_node search = doc.child("Search");
    if(search.empty())
    {
            _name="empty";
            _id=-7;
    }
    else
    {
        //pobranie nazwy i id dla klasy search(nazwy i id wyszukania)
        _name=search.attribute("name").value();
        istringstream buffer(search.attribute("id").value());
        buffer>>_id;
        //pobranie filtrow
        //obiekt odnoszacy sie do noda Filters
        xml_node filters=search.child("Filters");
        for (xml_node filtr = filters.child("Filter"); filtr; filtr = filtr.next_sibling("Filter"))
        {
            string* new_filter=new string(filtr.attribute("name").value());
            _filters.push_back(new_filter);
        }
        //pobranie Compare
        xml_node data=search.child("Data");
        for(xml_node com=data.child("Compare"); com; com=com.next_sibling("Compare"))
        {
            Compare* nc=new Compare();
           //elementy atribute
           string type=com.attribute("type").value();
           nc->setType(type);
           readC(com,nc);
           readA(com, nc);

           _comp.push_back(nc);
        }
    }
}
/// Destruktor
Search::~Search()
{
    int siz=_comp.size();
    for(int i=0; i<siz; ++i)
    {
        delete _comp[i];

    }
    _comp.clear();
    siz=_filters.size();
    for(int i=0; i<siz; ++i)
    {
        delete _filters[i];

    }
    _filters.clear();

}
/// Funkcja zwracająca nazwę zapytania
string Search::getName()
{
	return _name;
}
/// Funkcja zwracająca id zapytania jako string
string Search::getId()
{
	stringstream ss;//create a stringstream
    ss << _id;
    return ss.str();//return a string
}
/// Funkcja zwracająca id zapytania jako int
int Search::getIdI()
{
	return _id;
}
/// Funkcja nadająca nowa nazwę zapytania
void Search::setName(string n)
{
	_name=n;
}
/// Funkcja nadające nowe id zapytania
/// \param value wartość int nadawana id zapytania
void Search::setId(int value)
{
	_id=value;
}
/// Funkcja nadające nowe id zapytania
/// \param n wartość string konwertowana do int i przypisywana do id zapytania
void Search::setId(string n)
{

 istringstream buffer(n);
 buffer >>_id;

}
/// Funkcja dodająca nowy filtr
/// \param f wskaźnik do dodawanego filtru
void Search::addFilter(Filter* f)
{
    string* s=new string();
    s=f;
    _filters.push_back(s);
}
/// Funkcja dodająca nowe porównanie
/// \param add_c wskaźnik do nowego porównania, które zostanie dodane do zapytania(dodajemy kopię elementu)
void Search::addCompare(Compare* add_c)
{
    Compare* com=new Compare();
    com->Copy(add_c);
    _comp.push_back(com);
}
/// Funkcja zwracająca referencję do wektora reprezentującego szukanych filtrów
vector <Filter*>& Search::getFilters()
{
	return _filters;
 }
 /// Funkcja zwracająca referencję do wektora wskaźników do szukanych porównań
vector<Compare*>& Search::getComp()
{
    return _comp;
}
/// Funkcja pozwalająca załadować nowe zapytanie - obiekt reprezentuje drzewo nowego zapytani xml
/// \param xml nowe zapytanie XML
void Search::loadS(std::string xml)
{
    //wykasowanie istniejacego wzorca
    int siz=_comp.size();
    for(int i=0; i<siz; ++i)
    {
        delete _comp[i];

    }
    _comp.clear();
    siz=_filters.size();
    for(int i=0; i<siz; ++i)
    {
        delete _filters[i];

    }
    _filters.clear();
    //zapis nowego z xml

//utworzenie obiektu dokumentu xml
     xml_document doc;
//wczytanie struktury dokumrntu
    doc.load(xml.c_str());
    //obiekt odnoszący się do noda search
    xml_node search = doc.child("Search");
    if(search.empty())
    {
            _name="empty";
            _id=-7;
    }
    else
    {
        //pobranie nazwy i id dla klasy search(nazwy i id wyszukania)
        _name=search.attribute("name").value();
        istringstream buffer(search.attribute("id").value());
        buffer>>_id;
        //pobranie filtrow
        //obiekt odnoszacy sie do noda Filters
        xml_node filters=search.child("Filters");
        for (xml_node filtr = filters.child("Filter"); filtr; filtr = filtr.next_sibling("Filter"))
        {
            string* new_filter=new string(filtr.attribute("name").value());
            _filters.push_back(new_filter);
        }
        //pobranie Compare
        xml_node data=search.child("Data");
        for(xml_node com=data.child("Compare"); com; com=com.next_sibling("Compare"))
        {
            Compare* nc=new Compare();
           //elementy atribute
           string type=com.attribute("type").value();
           nc->setType(type);
           readC(com,nc);
           readA(com, nc);

           _comp.push_back(nc);
        }
    }
}
/// Funkcja pomocnicza do wczytywania elementów Compare, poniewaz nie znamy głębokości ich rekurencji
void Search::readA(xml_node node,Compare* c)
{
    for(xml_node atrib=node.child("Atrybute"); atrib;atrib=atrib.next_sibling("Atrybute"))
       {
           Atribute* at=new Atribute();
           at->setName(atrib.attribute("name").value());
           //compType
           at->setType(atrib.attribute("compType").value());
           at->setValue(atrib.attribute("value").value());

           c->addInfo(at);
       }
}
///Prywatna funkacja pomocnicza wczytujaca elementy Compare z xml
///\param c obirkt do ktorego dodajemy elementy
///\param node fragment drzewa w ktorym szukamy elementow Compare
void Search::readC(xml_node node,Compare* c)
{
    for(xml_node com=node.child("Compare"); com; com=com.next_sibling("Compare"))
    {
        Compare* nc=new Compare();
       //elementy atribute
       string type=com.attribute("type").value();
       nc->setType(type);

       readA(com, nc);
       //read Compare
       readC(com,nc);

       c->addInfo(nc);
    }

}
///funkcja zapisujaca gotowy zbior porowanań
void Search::setCompare(vector<Compare*> comp)
{
    int siz=_comp.size();

    for(int i=0; i<siz; ++i)
    {
        delete _comp[i];

    }
   // cout<<"sdfs"<<endl;
    _comp.clear();
    siz=comp.size();
    for(int i=0; i<siz; ++i)
    {
        Compare* c=new Compare();
        c->Copy(comp[i]);
        _comp.push_back(c);
    }
}
///Funkcja zapisujaca gotowy zbior filtrow
void Search::setFilters(vector<string*> comp)
{
    int siz=_filters.size();
    for(int i=0; i<siz; ++i)
    {
        delete _filters[i];

    }
    _filters.clear();
    siz=comp.size();
    for(int i=0; i<siz; ++i)
    {

        string* c=new string(comp[i]->c_str());

        _filters.push_back(c);
    }
}
