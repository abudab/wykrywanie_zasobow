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
string Info::getType()
{
	return _type;
}
/// Funkcja pozwalająca nadać typ informacji
/// \param type nazwa typu nadawana informacji
void Info::setType(string type)
{
	_type=type;
}
