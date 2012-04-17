#ifndef HEADER_46EFCDD057C01C40
#define HEADER_46EFCDD057C01C40

#ifndef INFO
#define INFO

#include <string>

class info
{
	protected:
		string type;

	public:
		info():type("non"){}
		info(string a):type(a){}

		virtual ~info();
};

#endif

#endif // header guard 
