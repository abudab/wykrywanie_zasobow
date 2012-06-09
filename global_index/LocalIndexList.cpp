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
  //std::cout<<"Content-type: text/html"<<std::endl<<std::endl;
  //core.getContentRead();
  
  core.initialize();
  core.beginHttpHeader(200);
  core.endHttpHeader();
  
  try
    {
      std::vector<std::string> local = db.getLocalIndexList();
      
      unsigned int size = local.size();
      
      std::cout << "<localIndexList>";
      
      for(unsigned int i=0; i < size; ++i)
	std::cout << "LocalIndex uri=\"" << local[i] <<"\" \\>";
        
      std::cout << "<\\localIndexList>";   
    }
  catch( std::exception& e)
    {
      std::cout << "Cos sie zjebalo" << std::endl;
      std::cout << e.what() << std::endl;
    }
  
  return 0;
}
