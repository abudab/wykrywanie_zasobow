#ifndef INFO
#define INFO
/////////////////////////////////////////////////////////
/// \file Info
/// \author Monika Godzwon
/// \brief  klasa Info, klasa podstawowa po której dziedzicy Atribute i Compare
////////////////////////////////////////////////////////
#include <string>
/// \class Info Prosta klasa pomocnicza
class Info
{
	public:
		Info();
		Info(std::string type);

		virtual ~Info();

		std::string getType();
		void        setType(std::string type);

    public:
		std::string _type;
};

#endif

