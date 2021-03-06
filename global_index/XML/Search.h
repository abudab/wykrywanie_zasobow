#include "Compare.h"

/////////////////////////////////////////////////////////
/// \file Search
/// \author Monika Godzwon
/// \brief  klasa search reprezentujaca zapytanie XML w postaci drzewa
////////////////////////////////////////////////////////

#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <string>
#include <vector>
#include "../pugi/pugixml.hpp"
#define Filter std::string
class Search{
	public:
		Search();
		Search(std::string xml);
		~Search();
		std::string getName();
		std::string getId();
		int getIdI();
		std::vector<Filter*>& getFilters();
		std::vector<Compare*>& getComp();

		void setName(std::string name);
		void setId(int id);
		void setId(std::string id);
		void addFilter(Filter* filt);
		void addCompare(Compare* com);
		void setCompare(std::vector<Compare*> comp);
		void setFilters(std::vector<Filter*> filter);
		void loadS(std::string xml);// pobiera XML

private:
		std::string _name;
		int _id;
		std::vector<Filter*> _filters;
		std::vector<Compare*> _comp;
		void readC(pugi::xml_node,Compare* c);
		void readA( pugi::xml_node, Compare* c);
};

#endif
