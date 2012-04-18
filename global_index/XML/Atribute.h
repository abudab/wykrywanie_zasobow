#ifndef _ATR_H
#define _ATR_H

#include <string>
#include "info.h"

class Atribute: public Info{

	private:
		std::string _name;
		//string type;
		std::string _value;//aby moznabylo obsluzyc:  <Atrybute type="Static" name="OS-Name" value="Debian 6 (Squeeze)" />

	public:
		Atribute();
		Atribute(std::string , std::string ,std::string);
		virtual ~Atribute();

		std::string  getName();
		std::string  getValue();
		int     getValueI();

		void setName(std::string);
		void setValue(int);
		void setValue(std::string);

};

#endif
