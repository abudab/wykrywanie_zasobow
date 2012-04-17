#include "info.h"

using namespace std;

Info::Info():_type("non")
{
}

Info::Info(string type):_type(type)
{
}

Info::~Info()
{
}

string Info::getType()
{
	return _type;
}

void Info::setType(string type)
{
	_type=type;
}
