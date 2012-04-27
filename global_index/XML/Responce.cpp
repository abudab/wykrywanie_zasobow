#include "Response.h"
#include "Monitor.h"
#include <sstream>
#include <iostream>


using namespace std;
/// Konstruktor domyślny nadaje _id=0
Response::Response():_id(0)
{
}
/// Konstruktor zależny od 2 parametrów
/// \param id wartość int przypisywana do _id
/// \param mon wektor wskaźników do Monitor zawierający opisy monitorów spełniających warunki zapytania
Response::Response(int id,vector <Monitor*> mon):_id(id), _mon(mon)
{
}
/// Destruktor
Response::~Response()
{
  /*  int siz=_mon.size();
    for(int i=0; i<siz; ++i)
    {
        delete _mon[i];
    }*/
    _mon.clear();
}
/// Funkcja zwracająca wartość _id odpowiedzi w postaci int
int Response::getId()
{
    return _id;
}
/// Funkcja nadająca wartość _id odpowiedzi
/// \param id wartość int nadawana _id
void Response::setId(int id)
{
    _id=id;
}
/// Funkcja nadająca wartość _id odpowiedzi
/// \param id string konwertowany na wartość int przypisywaną do _id odpowiedzi
void Response::setId(string id)
{
    istringstream buffer(id);
    buffer >>_id;
}
/// Funkcja zwracająca referencję do wektora wskaźników - zbioru monitorów spełniających warunki zapytania
vector<Monitor*>& Response::getMonitor()
{
    return _mon;
}
/// Funkcja dodająca Monitor do zbioru monitorów spełniających zapytanie
/// \param new_m wskaźnik do Monitora, który zostanie dodany
void Response::addMonitor(Monitor* new_m)
{

    Monitor* m=new Monitor(*new_m);
    _mon.push_back(m);

}
/// Funkcja ustalająca nowy zbiór monitorów. Bezpowrotnie kasuje poprzedni zbiór monitorów
/// \param mon zbiór monitorów spełniających zapytanie
void Response::setMonitors(vector <Monitor*> mon)
{
    int siz=_mon.size();
    for(int i=0; i<siz; ++i)
    {
        delete _mon[i];
    }
    _mon.clear();
    siz=mon.size();
    for(int i=0; i<siz; ++i)
    {
        Monitor* m=new Monitor(*(mon[i]));
        _mon.push_back(m);
    }

}
/// Funkcja zwracająca string będący XML-em reprezentującym odpowiedź na zapytanie
string Response::toXML()
{
    string xml="<Response id='";
    stringstream ss;
    ss << _id;
    xml+=ss.str();
    xml+="'>";
    int m_size=_mon.size();
    for(int i=0;i<m_size;++i)
    {
        xml+="<Monitor name='";
        xml+=_mon[i]->getName();
        xml+="'>";
        vector<Atribute*> ats=_mon[i]->getAtrib();
        int at_size=ats.size();
        for(int j=0;j<at_size;++j)
        {
            xml+="<Atrybute name='";
            xml+=ats[j]->getName();
            xml+="' compType='";
            xml+=ats[j]->getType();
            xml+="' value='";
            xml+=ats[j]->getValue();
            xml+="' />";
        }
        xml+="</Monitor>";
    }
    xml+="</Response>";
    return xml;
}
