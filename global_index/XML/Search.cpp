#include "Search.h"
#include <sstream>
using namespace std;

///Konstruktor domyslny klasy Search
Search::Search():_name("non"), _id(0)
{
    vector<Compare*> w;
    _comp=w;
    vector<string*> s;
    _filters=s;
}
Search::Search(string xml):_name("non"), _id(0)
{
    vector<Compare*> w;
    _comp=w;
    vector<string*> s;
    _filters=s;
//rezerwacja pamieci na Filtr i Compare -> zliczyc ilosc nodow w xml_dokument

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

//zwolnienie pamieci z Filtr i Compare
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

