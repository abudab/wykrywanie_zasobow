#ifndef _ATR_H
#define _ATR_H

#include <string>

class Atribute: public info{

	private:
		string name;
		//string type;
		string value;//aby moznabylo obsluzyc:  <Atrybute type="Static" name="OS-Name" value="Debian 6 (Squeeze)" />

	public:
		Atribute();
		Atribute(string , string ,string);
		virtual ~Atribute();

		string  getName();
		string  getValue();
		int     getValueI();

		void setName(string);
		void setValue(int);
		void setValue(string);

};

#endif
