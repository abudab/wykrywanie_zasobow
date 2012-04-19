#include "Atribute.h"
#include <sstream>
using namespace std;
/// Konstruktor domyślny. Nadaje domyślnie _type="non", _name="atrib", value="0"
Atribute::Atribute():Info(),_name("atrib"),  _value("0")
{
}
/// Konstruktor zalezny od 3 parametrów typu string
/// \param name - nazwa atrybutu
/// \param type - typ atrybutu
/// \param value - wartość typu
Atribute::Atribute(string name, string type,string value): Info(type),_name(name), _value(value)
{
}
/// Destruktor
Atribute::~Atribute()
{
}
/// Funkcja zwracająca string zawierający nazwę atrybutu
string Atribute::getName() const
{
	return _name;
}
/// Funkcja zwracająca string zawierający wartość atrybutu
string Atribute::getValue() const
{
	return _value;
}
/// Funcja zwracająca int zawierający wartość atrybutu
int Atribute::getValueI()
{
    istringstream buffer(_value);
    int id;
    buffer >>id;
	return id;
}
/// Funkcja nadająca nazwę atrybutu
/// \param nazwa nazwa atrybutu, która zostanie przypisana atrybutowi
void Atribute::setName(string nazwa)
{
	_name=nazwa;
}
/// Funkcja zmieniająca wartość atrybutu
/// \param val wartość int przypisywana atrybutowi
void Atribute::setValue(int val)
{
	stringstream ss;
    ss << val;
    _value=ss.str();
}

/// Funkcja zmieniająca wartość atrybutu
/// \param value wartość strin przypisywana atrybutowi
void Atribute::setValue(string value)
{
	_value=value;
}
/// Konstruktor kopiujący
void Atribute::Copy( Atribute& atrib)
{
        _name=atrib.getName();
        _type=atrib.getType();
        _value=atrib.getValue();

}
void Atribute::Copy( Atribute* atrib)
{
        _name=atrib->getName();
        _type=atrib->getType();
        _value=atrib->getValue();

}
