#ifndef _COMPARE_H_
#define _COMPARE_H_

#include <string>
#include <vector>
class Compare: public info{

	private:
	//string type;
	vector <info> Info;
	
	
	public:
	Compare();
	Compare(string);
	Compare(string, vector <info>);
	virtual ~Compare();
	string getType();
	vector <info>& getInfo();
	
	virtual void setType(string );
	
	void AddAtrib(Atribute);
	void setAtrib(vector <Atribute>);
	void setComp(vector <Compare>);
	
	string toString();
	
};

#endif