Poprawic metody

#include "Search.h"
#include <sstream>
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
	return name;
}
string Search::getIdI()
{
	stringstream ss;//create a stringstream
    ss << id;
    return ss.str();//return a string
}
int Search::getId()
{
	return id;
}
void Search::setName(string n)
{
	name=n;
}
void Search::setId(int value){
	id=value;
}
void Search::setId(string n){

 istringstream buffer(n);
 buffer >>id;

}
void Search::addFilter(Filter){
//zarezerwowanie pamieci o 1 element wiecej , przepisanei tablicy i ewntualna inkrementacja licznika elementów
//zwolnienie pamiêci
}
void Search::addCompare(Compare ){
//zarezerwowanie pamieci o 1 element wiecej , przepisanei tablicy i ewntualna inkrementacja licznika elementów
//zwolnienie pamiêci
}
vector <Filter>& Search::getFilter(){

	return filters
 
 }
vector<Compare>& Search::getComp(){

} 

