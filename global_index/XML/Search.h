#ifdef _DLL
#define PUGIXML_API __declspec(dllexport)
#else
#define PUGIXML_API __declspec(dllimport)
#endif
#include "pugixml.hpp"
#include "Compare.h"
#include "Filter.h"
/////////////////////////////////////////////////////////
/// \file Search
/// \author Monika Godzwon
/// \brief  klasa search reprezentujaca zapytanie XML w postaci drzewa 
////////////////////////////////////////////////////////

#ifndef _SEARCH_H_
#define _SEARCH_H_

#include <string>
#include <vector>
#define Filter string
class Search{
	private:
		string name;
		int id;
		vector <Filter> filters;
		vector <Compare> comp;
		
	public:
		Search();
		Search(String );//pobiera XML
		~Search();
		string getName();
		string getId();
		int getIdI();
		vector <Filter>& getFilters(); 
		vector<Compare>& getComp(); 
		
		void setName(string );
		void setId(int);
		void setId(string);
		void addFilter(Filter);
		void addCompare(Compare );
		void setCompare(vector<Compare>);
		void setFilters(vector<Filter>);
		void loadS(string );// pobiera XML
	
};

#endif