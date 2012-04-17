#ifndef _Response_H_
#define _Response_H_

#include <string>
#include "Atribute.h"
class Monitor{
	private:
		string name;
		vector <Atribute> atrib;
	public:
		Monitor();
		Monitor(string , vector <Atribute>);
		~Monitor();
		
		string getName();
		vector <Atribute>& getAtrib();
		
		void setName(string);
		void addAtrib(Atribute);
		void setAtribs(vector <Atribute>);
};

#endif