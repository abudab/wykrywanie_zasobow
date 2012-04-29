#include "Compare.h"
#include "info.h"
#include <sstream>
#include "../pugi/pugiconfig.hpp"
#include "../pugi/pugixml.hpp"
#include <iostream>
using namespace std;
/// Komstruktor domyślny generuje pusty wektor wskaźników do Info i _type="non"
Compare::Compare():Info()
{
}
/// Konstruktor generuje pusty wektor wskaźników do Info i _type ma nadawaną nazwę
/// \param type string reprezentujący nazwę, która zostanie przypisna jako typ porównania
Compare::Compare(string type):Info(type)
{
}
/// Konstruktoe zależy od parametrów string i vector<Info*>
/// \param type nadawany typ porównania
/// \param data dane w postaci vector<Info*> przechowywane w Compare
Compare::Compare(string type, vector<Info*> data):Info(type)
{
    int r=data.size();
    for(int i=0;i<r;++i)
        _data.push_back(data[i]->Copy());
}
///Konstruktor kopiujacy
Compare::Compare(Compare& org)
{
    _type=org.getType();
    int r=org.getInfo().size();
    for(int i=0;i<r;++i)
        _data.push_back(org.getInfo()[i]->Copy());
}
/// Destruktor zwalniający pamięć
Compare::~Compare()
{

    int siz=_data.size();
    for(int i=0; i<siz; ++i)
    {
        delete _data[i];

    }
    _data.clear();
}
/// Funkcja dodająca kolejną przechowywaną informację
/// \param data wskaźnik na obiekt klasy Atribute, dodawany do danych Compare
void Compare::addInfo(Atribute* data)
{
    Atribute* s=new Atribute();
    s->Copy(data);
    _data.push_back(s);
}
/// Funkcja dodająca kolejną przechowywaną informację
/// \param data wskaźnik na obiekt klasy Compare, dodawany do danych Compare
void Compare::addInfo(Compare* data)
{
    Compare* s=new Compare();
    s->Copy(data);
    _data.push_back(s);
}
/// Funkcja zwracająca wskaźnik do wektora z danymi Compare
vector<Info*>& Compare::getInfo()
{
    return _data;
}
/// Funkcja zwracająca string reprezentujący zawartość Compare
string Compare::toString()
{
    return " ";//TO DO in future
}
/// Funkcja zamieniająca dane znajdujące się w Compare na data
/// \param data dane w postaci wektoraz wskaźników Info wrzucane do Compare
void Compare::setInfo(vector<Info*> d)
{
    int siz=_data.size();
    for(int i=0; i<siz;++i)
        delete _data[i];

    _data.clear();

     int r=d.size();
    for(int i=0;i<r;++i)
        _data.push_back(d[i]->Copy());//bez Copy() bylo segmantation fault
}
/// Funkcja pomocnicza pozwalająca uzyskać kopię obiektu
void Compare::Copy(Compare& com)
{
    _type=com.getType();
    setInfo(com.getInfo());

}
/// Funkcja pomocnicza pozwalająca uzyskać kopię obiektu
void Compare::Copy(Compare* com)
{
    _type=com->getType();
    setInfo(com->getInfo());

}
///Funkcja zwracajaca kopię obiektu
Compare* Compare::Copy()
{
    Compare* wyn=new Compare(_type, _data);
    return wyn;
}
