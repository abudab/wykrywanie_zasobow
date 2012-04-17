#ifndef HEADER_46EFCDD057C01C40
#define HEADER_46EFCDD057C01C40

#ifndef INFO
#define INFO

#include <string>

class Info
{
	protected:
		std::string _type;

	public:
		Info();
		Info(std::string type);

		virtual ~Info();

		std::string getType();
		void        setType(std::string type);
};

#endif

#endif // header guard
