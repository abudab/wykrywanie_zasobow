#include "Compare.h"

using namespace std;

Compare::Compare(string type):Info(type)
{
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
    return " ";
}
