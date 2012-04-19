#include "Compare.h"
#include "info.h"
#include <sstream>
using namespace std;
Compare::Compare():Info()
{
    vector<Info*> p;
}

Compare::Compare(string type):Info(type)
{
    vector<Info*> p;
}

Compare::Compare(string type, vector<Info*> data):Info(type), _data(data)
{
}

Compare::~Compare()
{
    //TODO: Clear
    int siz=_data.size();
    for(int i=0; i<siz; ++i)
    {
        delete _data[i];

    }
    _data.clear();
}
void Compare::addInfo(Info* data)
{
    _data.push_back(data);
}
vector<Info*>& Compare::getInfo()
{
    return _data;
}
string Compare::toString()
{
    return " ";//TO DO in future
}
void Compare::setInfo(vector<Info*> data)
{
    _data=data;
}
