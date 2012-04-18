
#include "Monitor.h"
using namespace std;

Monitor::Monitor()
{
	_name="new_M";

}
Monitor::Monitor(string name, vector<Atribute*> atrib)
{
}
Monitor::~Monitor()
{
    _atrib.clear();
}
/*
string Monitor::getName()
{
    return _name;
}
vector<Atribute*>& Monitor::getAtrib()
{
    return _atrib;
}
void Monitor::setName(string n)
{
    _name=n;
}
void Monitor::addAtrib(Atribute* atrib)
{
    _atrib.push_back(atrib);
}
void Monitor::setAtribs(vector<Atribute*> new_a)
{
    _atrib=new_a;
}
*/
