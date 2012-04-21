#include "Search.h"
#include "Atribute.h"
#include <sstream>
#include "../pugi/pugixml.hpp"
//#include "../pugi/pugiconfig.hpp"


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
    vector<Compare*> w;
    _comp=w;
    vector<string*> s;
    _filters=s;
//utworzenie obiektu dokumentu xml
     xml_document doc;
//wczytanie struktury dokumrntu
    doc.load(xml.c_str());
    //obiekt odnoszący się do noda search
    xml_node search = doc.child("Search");

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

       for(xml_node atrib=com.child("Atrybute"); atrib;atrib=atrib.next_sibling("Atrybute"))
       {
           Atribute* at=new Atribute();
           at->setName(atrib.attribute("name").value());
           //compType
           at->setType(atrib.attribute("compType").value());
           at->setValue(atrib.attribute("value").value());
           nc->addInfo(at);
       }
       for(xml_node com2=com.child("Compare");com2;com2=com2.next_sibling("Compare"))
      {
          Compare* cc=new Compare();
          cc->setType(com2.attribute("type").value());
          readC(cc, com2);
          nc->addInfo(cc);
      }

       _comp.push_back(nc);
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
    xml_document doc;
//wczytanie struktury dokumrntu
    doc.load(xml.c_str());
    //obiekt odnoszący się do noda search
    xml_node search = doc.child("Search");

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
       for(xml_node atrib=com.child("Atrybute"); atrib;atrib=atrib.next_sibling("Atrybute"))
       {
           Atribute* at=new Atribute();
           at->setName(atrib.attribute("name").value());
           //compType
           at->setType(atrib.attribute("compType").value());
           at->setValue(atrib.attribute("value").value());
           nc->addInfo(at);
       }
       for(xml_node com2=com.child("Compare");com2;com2=com2.next_sibling("Compare"))
      {
          Compare* cc=new Compare();
          cc->setType(com2.attribute("type").value());
          readC(cc, com2);
          nc->addInfo(cc);
      }

       _comp.push_back(nc);
    }
}
/// Funkcja pomocnicza do wczytywania elementów Compare, poniewaz nie znamy głębokości ich rekurencji
void Search::readC(Compare* c, xml_node node)
{
    for(xml_node com=node.child("Compare"); com; com=com.next_sibling("Compare"))
    {
        Compare* nc=new Compare();
       //elementy atribute
       string type=com.attribute("type").value();
       nc->setType(type);

       for(xml_node atrib=com.child("Atrybute"); atrib;atrib=atrib.next_sibling("Atrybute"))
       {
           Atribute* at=new Atribute();
           at->setName(atrib.attribute("name").value());
           //compType
           at->setType(atrib.attribute("compType").value());
           at->setValue(atrib.attribute("value").value());
           nc->addInfo(at);
       }
       for(xml_node com2=com.child("Compare");com2;com2=com2.next_sibling("Compare"))
      {
          Compare* cc=new Compare();
          cc->setType(com2.attribute("type").value());
          readC(cc, com2);
          nc->addInfo(cc);
      }

       _comp.push_back(nc);
    }

}
void Search::setCompare(vector<Compare*> comp)
{
    int siz=_comp.size();
    for(int i=0; i<siz; ++i)
    {
        delete _comp[i];

    }
    _comp.clear();
    siz=comp.size();
    for(int i=0; i<siz; ++i)
    {
        Compare* c=new Compare();
        c->Copy(comp[i]);
        _comp.push_back(c);
    }
}
