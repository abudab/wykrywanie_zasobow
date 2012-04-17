#ifndef _Response_H_
#define _Response_H_

#include <string>
#include <vector>
/////////////////////////////////////////////////////////
/// \file Response
/// \author Monika Godzwon
/// \brief  klasa Responce reprezentujaca odpowiedz XML monitorow w postaci drzewa 
////////////////////////////////////////////////////////
class Response{
	private:
		int id;
		vector <Monitor> mon;
	public:
		Response();
		Response(int,vector <Monitor>);
		int getId();
		void setId(int);
		void setId(string );
		vector <Monitor>& getMonitor();
		void addMonitor(Monitor );
		void setMonitors(vector <Monitor>);
		
		string toXML();
		
		
};

#endif