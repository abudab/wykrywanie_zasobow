#ifndef INFO
#define INFO

#include <string>

class Info
{
	public:
		std::string _type;

	public:
		Info();
		Info(std::string type);

		virtual ~Info();

		std::string getType();
		void        setType(std::string type);
};

#endif

