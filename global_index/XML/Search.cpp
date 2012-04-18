

#include "Search.h"
#include <sstream>
using namespace std;

///Konstruktor domyslny klasy Search
Search::Search()
{
//rezerwacja pamieci na Filtr i Compare
}
Search::Search(string a)
{
//rezerwacja pamieci na Filtr i Compare -> zliczyc ilosc nodow w xml_dokument
//pobraz informacje o nazwie i id
}
Search::~Search()
{
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
void Search::addFilter(Filter){
//zarezerwowanie pamieci o 1 element wiecej , przepisanei tablicy i ewntualna inkrementacja licznika elementów
//zwolnienie pamiêci
}
void Search::addCompare(Compare ){
//zarezerwowanie pamieci o 1 element wiecej , przepisanei tablicy i ewntualna inkrementacja licznika elementów
//zwolnienie pamiêci
}
vector <Filter*>& Search::getFilters()
{
	return _filters;
 }
vector<Compare*>& Search::getComp()
{
    return _comp;
}

