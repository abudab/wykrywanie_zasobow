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
using std::stringstream;

/////////////////
// CONSTRUCTOR //
/////////////////#######################################

GlobalCache::GlobalCache( NetController *net )
{
  //cout << "Creating GlobalCache" << endl;
  qd = new QueryDispatcher();
  db = new DatabaseStorage( "localhost", "przespolowe", "a9M9PtDzgst5RFD", "5532" );
  this->net = net;
}

////////////////
// DESTRUCTOR //
////////////////#######################################

GlobalCache::~GlobalCache()
{
  //cout << "Deleting GlobalCache" << endl;
  delete(qd);
  delete(db);
}


////////////////
// setRequest //
////////////////#######################################

void GlobalCache::setRequest( Search* srch, string id )
{
  //cout << "Setting Request ..." << endl;
  vector <string> sql_query = vector<string>();

  vector <Filter*> filters = srch->getFilters();
  vector <Filter*>::iterator f;

  vector <string> *compare_items = new vector <string>();
  vector <Compare*> compares = srch->getComp();
  if( ! compares.empty() ) {
    Compare *c = compares.at(0);

    walkTree( c, compare_items );
  }

  sql_query.push_back( "SELECT " );

  for( f=filters.begin(); f!=filters.end(); ++f) {
    sql_query.push_back( quote(**f) );
    sql_query.push_back( ", " );
  }

  sql_query.pop_back();

  sql_query.push_back( " FROM static_resources " );

  if( ! compare_items->empty() ){
    sql_query.push_back(" WHERE ");
    for( vector<string>::iterator it=compare_items->begin(); it!=compare_items->end(); ++it)
      sql_query.push_back( *it + " " );
  }
  sql_query.push_back(";");


  std::string* pstmp = db->getResponse( id );

  if( pstmp )
    delete pstmp;

  stringstream ss;

  for( vector<string>::iterator it=sql_query.begin(); it!=sql_query.end(); ++it)
    ss << *it ;

  db->getData(ss.str().c_str(), id);
}


/////////////////
// getResponse //
/////////////////#######################################

string* GlobalCache::getResponse( string id )
{
  //cout << "Getting response #" << id << " ..." << endl;

  return db->getResponse( id );
}


//////////////
// walkTree //
//////////////#######################################

void GlobalCache::walkTree( Info *i, vector <string> *sv )
{
  string type = i->getType();

  if( typeid( *i ) == typeid( Compare ) ){
    Compare* c = dynamic_cast<Compare*>(i);
    bool first = true;

    for( vector<Info*>::iterator it = c->getInfo().begin(); it != c->getInfo().end(); ++it ) {
      if( !first ) sv->push_back( type );
      sv->push_back("(");
      walkTree( *it, sv );
      sv->push_back(")");
      first = false;
    }
  } else {
    Atribute* a = dynamic_cast<Atribute*>(i);
    sv->push_back( quote(validate(a->getName(), "[a-zA-Z\\-]{3,32}")) );
    sv->push_back( validate(a->getType(), "([><=]{1,2}|REGEX)") );
    sv->push_back( validate(a->getValue(), "([0-9]{1,10}|[a-zA-Z0-9]{2,32})") );
  }
}

//////////////
// validate //
//////////////#######################################

std::string GlobalCache::validate( std::string text, const char* regex )
{
  //  FIXME: Importnant - proper input validation!!!
  //  boost::regex re( regex.c_str() );
  return text;
}


///////////
// quote //
///////////#######################################

std::string GlobalCache::quote( std::string text )
{
  return "\"" + text + "\"";
}


/////////////////
// saveRequest //
/////////////////#######################################

void GlobalCache::saveRequest( std::string id, std::string data )
{
  db->storeRequest( data, id );
}


////////////////
// getRequest //
////////////////#######################################

/**
   RETURNS LAST SORED INDEX
 */
std::pair<std::string,std::string>*  GlobalCache::getRequest( void )
{
  return db->getRequest();
}


////////////////////////
// registerLocalIndex //
////////////////////////#######################################

void GlobalCache::registerLocalIndex( std::string url )
{
  db->registerLocalIndex( url );
}

//////////////////////
// deleteLocalIndex //
//////////////////////#######################################

void GlobalCache::deleteLocalIndex( std::string url )
{
  db->deleteLocalIndex( url );
}

////////////
// update //
////////////#######################################

bool GlobalCache::update( void )
{
  // BLOCKER: get_all_local_indexes()
}




