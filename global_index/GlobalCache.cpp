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

#include "GlobalCache.hxx"

using std::cout;
using std::endl;

/////////////////
// CONSTRUCTOR //
/////////////////#######################################

GlobalCache::GlobalCache()
{
  cout << "Creating GlobalCache" << endl;
  qd = new QueryDispatcher();
  db = new DatabaseStorage( "localhost", "przespolowe", "a9M9PtDzgst5RFD", "5532" );
}

////////////////
// DESTRUCTOR //
////////////////#######################################

GlobalCache::~GlobalCache()
{
  cout << "Deleting GlobalCache" << endl;
  delete(qd);
  delete(db);
}


////////////////
// setRequest //
////////////////#######################################

void GlobalCache::setRequest( const Search* s, unsigned int id )
{
  cout << "Setting Request ..." << endl;

  const char* sql_query = qd->dispatch("");
  db->getData(sql_query);
}


/////////////////
// getResponse //
/////////////////#######################################

Response* GlobalCache::getResponse( unsigned int id )
{
  cout << "Getting response ..." << endl;

  return NULL;
}
