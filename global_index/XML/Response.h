#ifndef _Response_H_
#define _Response_H_



#include <string>
#include <vector>

/////////////////////////////////////////////////////////
/// \file Response
/// \author Monika Godzwon
/// \brief  klasa Responce reprezentujaca odpowiedz XML monitorow w postaci drzewa
////////////////////////////////////////////////////////


#include "Monitor.h"

class Response{

	public:
		Response();
		Response(int id,std::vector <Monitor*> mon);

		int getId();
		void setId(int id);
		void setId(std::string id );
		std::vector <Monitor*>& getMonitor();
		void addMonitor(Monitor new_m);
		void setMonitors(std::vector <Monitor*> mon);

		std::string toXML();

    private:
		int _id;
		std::vector <Monitor*> _mon;


};

#endif
