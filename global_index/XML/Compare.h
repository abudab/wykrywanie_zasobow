#ifndef _COMPARE_H_
#define _COMPARE_H_

#include <string>
#include <vector>

#include "info.h"

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



private:
	std::vector<Info*> _data;



};

#endif