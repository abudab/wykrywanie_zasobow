#include "Response.h"
#include "Monitor.h"
using namespace std;

Response::Response():_id(0)
{
    vector<Monitor*> aa;
    _mon=aa;
}

Response::Response(int id,vector <Monitor*> mon):_id(id), _mon(mon)
{
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
void Response::addMonitor(Monitor new_m)
{
    _mon.push_back(new_m);
}
void Response::setMonitors(vector <Monitor*> mon)
{

}
string Response::toXML() //TO DO
{
    return "xml";
}
