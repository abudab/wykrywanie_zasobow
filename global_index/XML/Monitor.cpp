#include "Monitor.h"

using namespace std;
/// Konstruktor domyślny nadający monitorowi nazwę "new_M"
Monitor::Monitor():_name("new_M")
{
}
/// Konstruktor zależny od dwóch parametrów name i atrib
/// \param name string przypisywany jako nazwa atrybutu
/// \param atrib wektor atrybutów, które zawiera podany zasób
Monitor::Monitor(string name, vector<Atribute*> atrib):_name(name), _atrib(atrib)
{
}
/// Destruktor
Monitor::~Monitor()
{

    int siz=_atrib.size();
    for(int i=0; i<siz; ++i)
    {
        delete _atrib[i];

    }
        _atrib.clear();
}
/// Funkcja zwracająca nazwę monitora/zasobu
string Monitor::getName()
{
    return _name;
}
/// Funkcja zwracająca wskaźnik do wektora z Atrybutami monitora/zasobu
vector<Atribute*>& Monitor::getAtrib()
{
    return _atrib;
}
/// Funkcja ustawiająca nazwę monitora
/// \param name string reprezentujący przypisywaną nazwę monitora
void Monitor::setName(string name)
{
    _name=name;
}
/// Funkcja pozwalająca dodać jeden atrybut do zbioru juz istniejącego
/// \param atrib dodawany atrybut
void Monitor::addAtrib(Atribute* atrib)
{
   Atribute* ati=new Atribute(*atrib);
    _atrib.push_back(ati);
}
/// Funkcja zamieniająca vektor atrybutów na nowy
/// \param new_a wektor nowych atrybutów
void Monitor::setAtribs(vector<Atribute*> new_a)
{
    int siz=_atrib.size();
    for(int i=0; i<siz; ++i)
    {
        delete _atrib[i];

    }
    _atrib.clear();
    siz=new_a.size();
    //_atrib.
    for(int i=0; i<siz; ++i)
    {
        Atribute* p=new Atribute(*new_a[i]);
        _atrib.push_back(p);
    }

}
/// Funkcja kopiująca obiekt
void Monitor::Copy(Monitor* m)
{
    _name=m->getName();
    setAtribs(m->getAtrib());
}
/// Funkcja kopiująca obiekt
void Monitor::Copy(Monitor& m)
{
    _name=m.getName();
    setAtribs(m.getAtrib());
}
