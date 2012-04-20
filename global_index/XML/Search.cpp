#include "Search.h"
#include "Atribute.h"
#include <sstream>
#include "../pugi/pugixml.hpp"
//#include "../pugi/pugiconfig.hpp"


using namespace std;
using namespace pugi;
///Konstruktor domyslny klasy Search
Search::Search():_name("non"), _id(0)
{
    vector<Compare*> w;
    _comp=w;
    vector<string*> s;
    _filters=s;

}
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
string Search::getName()
{
	return _name;
}
string Search::getId()
{
	stringstream ss;//create a stringstream
    ss << _id;
    return ss.str();//return a string
}
int Search::getIdI()
{
	return _id;
}
void Search::setName(string n)
{
	_name=n;
}
void Search::setId(int value)
{
	_id=value;
}
void Search::setId(string n)
{

 istringstream buffer(n);
 buffer >>_id;

}
void Search::addFilter(Filter* f)
{
    string* s=new string();
    s=f;
    _filters.push_back(s);
}
void Search::addCompare(Compare* add_c)
{
    Compare* com=new Compare();
    com->Copy(add_c);
    _comp.push_back(com);
}
vector <Filter*>& Search::getFilters()
{
	return _filters;
 }
vector<Compare*>& Search::getComp()
{
    return _comp;
}
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

