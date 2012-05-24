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

#include "QueryDispatcher.hxx"

using std::cout;
using std::endl;
using std::string;

/////////////////
// CONSTRUCTOR //
/////////////////#######################################

QueryDispatcher::QueryDispatcher()
{
  //cout << "Creating QueryDispatcher" << endl;
}

////////////////
// DESTRUCTOR //
////////////////#######################################

QueryDispatcher::~QueryDispatcher()
{
  //cout << "Deleting QueryDispatcher" << endl;  
}


//////////////
// DISPATCH //
//////////////#######################################

const char* QueryDispatcher::dispatch( const char* query) const
{
  //cout << "Dispatching" << endl;  
  return "SELECT * FROM static_resources WHERE os='Linux' AND country='PL'";
}
