#include <iostream>
	#include <typeinfo>
	#include "pugi/pugiconfig.hpp"
	#include "pugi/pugixml.hpp"
	using namespace std;
	//#include "XML/Monitor.h"
	#include <vector>
	#include "XML/Registration.h"

	//using namespace pugi;
	int main()
	{
	    int ok=0;
	    int fail=0;
	    string name="non";
	    string ad="http://10.0.0.1/IndeksLokalny";
	    string xml1("<?xml version='1.0' ?> <>");
	    string xml2("<Registration address='http://10.0.0.1/IndeksLokalny' /> <>");
	    string xml3("<?xml version='1.0' ?> <Registration address='http://10.0.0.1/IndeksLokalny' />");
	    string xml4("<Registration address='http://10.0.0.1/IndeksLokalny' inny='efregreg'/>");
	    string xml5("<Registration addres='http://10.0.0.1/IndeksLokalny' />");
	    string xml6("<Registration addres='http://10.0.0.2/IndeksLokalny' address='http://10.0.0.1/IndeksLokalny' />");

	    cout<<"Konstruktor domyslny -> ";
	    Registration r;
	    if(r.Getaddress()==name)
        {
	        ++ok;
	        cout<<"OK :"<<r.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"FAIL "<<endl;

	    }
        cout<<"Konstruktor od stringa: "<<endl;
        cout<<"\tniepoprawnie zdefiniowany:"<<endl;
        Registration r1(xml1);
	    if(r1.Getaddress()==name)
        {
	        ++ok;
	        cout<<"\t\tOK :"<<r1.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"\t\tFAIL "<<endl;

	    }

        Registration r5(xml5);
	    if(r5.Getaddress()==name)
        {
	        ++ok;
	        cout<<"\t\tOK :"<<r5.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"\t\tFAIL "<<endl;

	    }
        cout<<"\tzawierajacy poprawny fragment:"<<endl;
        Registration r2(xml2);
	    if(r2.Getaddress()==ad)
        {
	        ++ok;
	        cout<<"\t\tOK :"<<r2.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"\t\tFAIL "<<endl;

	    }

        Registration r3(xml3);
	    if(r3.Getaddress()==ad)
        {
	        ++ok;
	        cout<<"\t\tOK :"<<r3.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"\t\tFAIL "<<endl;

	    }

	    Registration r4(xml4);
	    if(r4.Getaddress()==ad)
        {
	        ++ok;
	        cout<<"\t\tOK :"<<r4.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"\t\tFAIL "<<endl;

	    }
        Registration r6(xml6);
	    if(r6.Getaddress()==ad)
        {
	        ++ok;
	        cout<<"\t\tOK :"<<r6.Getaddress()<<endl;
	    }
	    else
	    {
	        ++fail;
	        cout<<"\t\tFAIL "<<endl;

	    }
    cout<<endl<<"Przeprowadzono "<<fail+ok<<" testów, gdzie:"<<endl<<"-> Poprawnych: "<<ok<<endl<<"-> Niepoprawnych: "<<fail<<endl;
	    return 0;
	}

