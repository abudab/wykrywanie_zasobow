#ifndef _COMPARE_H_
#define _COMPARE_H_
/////////////////////////////////////////////////////////
/// \file Compare
/// \author Monika Godzwon
/// \brief  klasa Compare, dziedziczy po Info, zawiera informacje o sposobie porównania
////////////////////////////////////////////////////////
#include <string>
#include <vector>

#include "info.h"
/// \class Compare
class Compare: public Info
{
public:
	Compare();
	Compare(std::string type);
	Compare(std::string type, std::vector<Info*> data);
	virtual ~Compare();

	void addInfo(Info* data);
	void setInfo(std::vector<Info*> data);
    std::vector <Info*>& getInfo();

	std::string toString();
    virtual void Copy(Compare& atrib);
    virtual void Copy(Compare* atrib);


private:
	std::vector<Info*> _data;



};

#endif
