#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <vector>

#include "Net/NetController.h"
#include "db/GlobalCache.hxx"

int main()
{
  NetController core;
  GlobalCache db(&core);    
  
  
  core.initialize();
  core.beginHttpHeader(200);
  core.endHttpHeader();
  
  try
    {
      std::vector<std::string> local = db.getLocalIndexList();
      
      unsigned int size = local.size();
      
      std::cout << "<localIndexList>";
      
      for(unsigned int i=0; i < size; ++i)
	std::cout << "<LocalIndex uri=\"" << local[i] <<"\" />";
        
      std::cout << "</localIndexList>" << std::endl;   
    }
  catch( std::exception& e)
    {
      std::cout << "Cos poszlo nie tak" << std::endl;
      std::cout << e.what() << std::endl;
    }
  
  return 0;
}
