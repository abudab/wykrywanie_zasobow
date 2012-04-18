#ifndef _Monitor_H_
#define _Monitor_H_
/////////////////////////////////////////////////////////
/// \file Monitor
/// \author Monika Godzwon
/// \brief  klasa Monitor, reprezentuje zasoby monitora
////////////////////////////////////////////////////////

#include <string>
#include <vector>

#include "Atribute.h"
/// \class Monitor
class Monitor{

	public:
		Monitor();
		Monitor(std::string name , std::vector<Atribute> atrib);
		~Monitor();

		std::string getName();
		std::vector <Atribute>& getAtrib();

		void setName(std::string name);
		void addAtrib(Atribute atrib);
		void setAtribs(std::vector <Atribute> new_atrib);

    private:
		std::string _name;
		std::vector <Atribute> _atrib;
};

#endif
