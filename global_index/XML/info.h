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
		virtual void Copy(Info& data);
		virtual void Copy(Info* data);
		virtual Info* Copy();

		std::string getType()const;
		void        setType(std::string type);


    public:
		std::string _type;
};

#endif

