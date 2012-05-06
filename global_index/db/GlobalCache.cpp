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
using std::string;
using std::vector;

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

void GlobalCache::setRequest( Search* srch, unsigned int id )
{
  cout << "Setting Request ..." << endl;
  const char* sql_query;
 
  vector <Filter*> filters = srch->getFilters();
  vector <Filter*>::iterator f;

  vector <Compare*> compares = srch->getComp();
  Compare *c = compares.at(0);
  vector <string> *compare_items = new vector <string>();

  /* *** */

  for( f=filters.begin(); f!=filters.end(); ++f) 
    cout << **f << endl;
    
  walkTree( c, compare_items );

  //db->getData(sql_query);
}


/////////////////
// getResponse //
/////////////////#######################################

Response* GlobalCache::getResponse( unsigned int id )
{
  cout << "Getting response ..." << endl;

  return NULL;
}


//////////////
// walkTree //
//////////////#######################################

void GlobalCache::walkTree( Info *i, vector <string> *sv )
{
  string type = i->getType();
}

