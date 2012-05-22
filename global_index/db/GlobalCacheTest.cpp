/*

    #################################################################
    # 								    #
    # ⌬ NAME:		C++ TEMPLATE CLASS			    #
    # ⌬ AUTHOR:	A. JANUSZ				    #
    # ⌬ DESC:		SOURCE CODE FILE			    #
    #								    #
    #   ⌬      FACULTY OF PHYSICS AND COMPUTER SCIENCE       ⌬     #
    #   ⌬  UNIVERSITY OF SCIENCE AND TECHNOLOGY AGH, CRACOW  ⌬     #
    # 								    #
    #################################################################

*/

#include <cstdio>
#include <iostream>

#include "GlobalCache.hxx"


using std::endl;
using std::cout;
using std::string;
using std::vector;

int main(){
  
  GlobalCache gc = GlobalCache();

  /*
  string str("<Search name='request_001' id='12345'><Filters><Filter name='CPU-Frequency' />"
	     "<Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters><Data><Compare type='OR'>"
	     "<Compare type='AND'><Atrybute name='CPU-Frequency' compType='>=' value='1000' />"
	     "<Atrybute name='CPU-Frequency' compType='<=' value='1500' /></Compare>"
	     "<Atrybute name='MEM-Count' compType='>=' value='4000' /></Compare></Data></Search>");
  */

  string str("<Search name='request_001' id='12345'><Filters><Filter name='CPU-Frequency' />"
	     "<Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters></Data></Search>");

  Search srch( str );

  gc.setRequest( &srch, "666" );
  cout << "Getting for the first time ..." << endl;
	  
  string *response = gc.getResponse( "666" );
  if( response != NULL ){
      cout << response->c_str() << endl;
  }

  return 0;
}
