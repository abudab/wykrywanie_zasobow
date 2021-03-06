#ifndef _ATR_H
#define _ATR_H
/////////////////////////////////////////////////////////
/// \file Atribute
/// \author Monika Godzwon
/// \brief  klasa Atribute, dziedziczy po Info, zawiera podstawowe dane
////////////////////////////////////////////////////////
#include <string>
#include "info.h"
/// \class Atribute
class Atribute: public Info{

    public:
		Atribute();
		Atribute(std::string name, std::string type,std::string value);
		Atribute(Atribute& org);


		virtual ~Atribute();
		virtual void Copy(Atribute& atrib);
		virtual void Copy(Atribute* atrib);
		virtual Atribute* Copy();

		std::string  getName()const;
		std::string  getValue()const;
		int          getValueI();

		void setName(std::string name);
		void setValue(int value);
		void setValue(std::string value);

private:
		std::string _name;
		std::string _value;

};

#endif
