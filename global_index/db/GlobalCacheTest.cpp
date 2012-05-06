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

  string str("<Search name='request_001' id='12345'><Filters><Filter name='CPU-Frequency' />"
	     "<Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters><Data><Compare type='OR'>"
	     "<Compare type='AND'><Atrybute name='CPU-frequency' compType='>=' value='1.0GHz' />"
	     "<Atrybute name='CPU-frequency' compType='<=' value='2.0GHz' /></Compare>"
	     "<Atrybute name='MEM-Count' compType='>=' value='4GB' /></Compare></Data></Search>");
  
  Search srch( str );

  gc.setRequest( &srch, 666 );
  gc.getResponse( 666 );
  gc.getResponse( 666 );
  gc.getResponse( 666 );

  return 0;
}
