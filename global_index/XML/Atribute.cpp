#include <Atribute.h>

using namespace std;

Atribute::Atribute():name("atrib"), type("non"), value("0")
{
}

Atribute::Atribute(string n, string t,string v):name(n), type(t), value(v)
{
}

Atribute::~Atribute()
{
}

string Atribute::getName()
{
	return name;
}

string Atribute::getValue()
{
	return value;
}

int Atribute::getValueI()
{
	return value;
}

void Atribute::setName(string n)
{
	name=n;
}

void Atribute::setValue(int val)
{
	stringstream ss;
    ss << val;
    value=ss.str();
}

void Atribute::setValue(string v)
{
	value=v;
}
