#include "Atribute.h"
#include <sstream>
using namespace std;

Atribute::Atribute():_name("atrib"),  _value("0")
{
}

Atribute::Atribute(string name, string type,string value): Info(type),_name(name), _value(value)
{
}

Atribute::~Atribute()
{
}

string Atribute::getName()
{
	return _name;
}

string Atribute::getValue()
{
	return _value;
}

int Atribute::getValueI()
{
    istringstream buffer(_value);
    int id;
    buffer >>id;
	return id;
}

void Atribute::setName(string n)
{
	_name=n;
}

void Atribute::setValue(int val)
{
	stringstream ss;
    ss << val;
    _value=ss.str();
}

void Atribute::setValue(string v)
{
	_value=v;
}
