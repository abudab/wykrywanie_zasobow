#include "Compare.h"
#include "info.h"
#include <sstream>
#include "../pugi/pugiconfig.hpp"
#include "../pugi/pugixml.hpp"
using namespace std;
/// Komstruktor domyślny generuje pusty wektor wskaźników do Info i _type="non"
Compare::Compare():Info()
{
    vector<Info*> p;
    _data=p;
}
/// Konstruktor generuje pusty wektor wskaźników do Info i _type ma nadawaną nazwę
/// \param type string reprezentujący nazwę, która zostanie przypisna jako typ porównania
Compare::Compare(string type):Info(type)
{
    vector<Info*> p;
    _data=p;
}
/// Konstruktoe zależy od parametrów string i vector<Info*>
/// \param type nadawany typ porównania
/// \param data dane w postaci vector<Info*> przechowywane w Compare
Compare::Compare(string type, vector<Info*> data):Info(type), _data(data)
{
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
/// \param data wskaźnik na obiekt klasy Info, dodawany do danych Compare
void Compare::addInfo(Info* data)
{
    Info* s=new Info();
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
void Compare::setInfo(vector<Info*> data)
{
    int siz=_data.size();
    for(int i=0; i<siz;++i)
        delete _data[i];
    _data.clear();
    siz=data.size();
    for(int i=0;i<siz;++i)
    {
        Info* p=new Info();
        p->Copy(data[i]);
        _data.push_back(p);

    }
}
void Compare::Copy(Compare& com)
{
    _type=com.getType();
    setInfo(com.getInfo());
}
void Compare::Copy(Compare* com)
{
    _type=com->getType();
    setInfo(com->getInfo());
}
