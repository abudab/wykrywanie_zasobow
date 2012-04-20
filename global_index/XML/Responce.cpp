#include "Response.h"
#include "Monitor.h"
#include <sstream>

using namespace std;

Response::Response():_id(0)
{
    vector<Monitor*> aa;
    _mon=aa;
}

Response::Response(int id,vector <Monitor*> mon):_id(id), _mon(mon)
{
}
Response::~Response()
{
    int siz=_mon.size();
    for(int i=0; i<siz; ++i)
    {
        delete _mon[i];
    }
    _mon.clear();
}
int Response::getId()
{
    return _id;
}
void Response::setId(int id)
{
    _id=id;
}
void Response::setId(string id)
{
    istringstream buffer(id);
    buffer >>_id;
}
vector<Monitor*>& Response::getMonitor()
{
    return _mon;
}
void Response::addMonitor(Monitor* new_m)
{
    Monitor* mon_n=new Monitor();
    mon_n->Copy(new_m);
    _mon.push_back(mon_n);
}
void Response::setMonitors(vector <Monitor*> mon)
{
    int siz=_mon.size();
    for(int i=0; i<siz; ++i)
    {
        delete _mon[i];
    }
    _mon.clear();
    siz=mon.size();
    for(int i=0; i<siz; ++i)
    {
        Monitor* m=new Monitor();
        m->Copy(mon[i]);
        _mon.push_back(m);
    }

}
string Response::toXML()
{
    string xml="<Response id='";
    stringstream ss;
    ss << _id;
    xml+=ss.str();
    xml+="'>";
    int m_size=_mon.size();
    for(int i=0;i<m_size;++i)
    {
        xml+="<Monitor name='";
        xml+=_mon[i]->getName();
        xml+="'>";
        vector<Atribute*> ats=_mon[i]->getAtrib();
        int at_size=ats.size();
        for(int j=0;j<at_size;++j)
        {
            xml+="<Atrybute name='";
            xml+=ats[j]->getName();
            xml+="' compType='";
            xml+=ats[j]->getType();
            xml+="' value='";
            xml+=ats[j]->getValue();
            xml+="' />";
        }
        xml+="</Monitor>";
    }
    xml+="</Response>";
    return xml;
}
