#include "info.h"

using namespace std;
/// Konstruktor domyślny _type="non"
Info::Info():_type("non")
{
}
/// Konstruktor zalezny od jednego parametru typu string
/// \param type Wartość string przypisywana do typu
Info::Info(string type):_type(type)
{
}
/// Destruktor
Info::~Info()
{
}
/// Funkcja zwracająca stringa reprezentującego typ inforamcji
string Info::getType()const
{
	return _type;
}
/// Funkcja pozwalająca nadać typ informacji
/// \param type nazwa typu nadawana informacji
void Info::setType(string type)
{
	_type=type;
}
/// Funkcja kopiująca obiekt klasy
void Info::Copy(Info& data)
{
    _type=data.getType();
}
/// Funkcja kopiująca obiekt klasy
void Info::Copy(Info* data)
{
    _type=data->getType();
}
Info* Info::Copy()
{
    Info* wyn=new Info(_type);
    return wyn;
}
