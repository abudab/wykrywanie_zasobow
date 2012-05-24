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

#include "DatabaseStorage.hxx"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;

/////////////////
// CONSTRUCTOR //
/////////////////#######################################

DatabaseStorage::DatabaseStorage(const char* host, const char* user, const char* pass, const char* port )
{
  //cout << "Creating DatabaseStorage" << endl;

  string cred = "";
  cred += "host=";
  cred += host;
  cred += " dbname=pz-global";
  cred += " user=";
  cred += user;
  cred += " password=";
  cred += pass;
  cred += " port=";
  cred += port;

  con = new pqxx::connection( cred.c_str() );
}

////////////////
// DESTRUCTOR //
////////////////#######################################

DatabaseStorage::~DatabaseStorage()
{
  //cout << "Deleting DatabaseStorage" << endl;

  delete(con);
}


/////////////
// GETDATA //
/////////////#######################################

void DatabaseStorage::getData( const char* sql_query, string id )
{

  //cout << "DATABASE: " << sql_query << endl;

  pqxx::work txn(*con);
  pqxx::result res = txn.exec( sql_query );
  txn.commit();

  Response resp = Response();
  resp.setId( id );
    
  int size = res.size();
  for( int i=0; i<size; ++i ){
    Monitor* mon = new Monitor();
    Atribute* atr;

    const pqxx::result::tuple row = res[i];
    for(pqxx::result::tuple::const_iterator field = row.begin(); field!=row.end(); ++ field){
      atr = new Atribute(field.name(), "Static", field.c_str());
      mon->addAtrib(atr);
    }

    resp.addMonitor(mon);
  }

  storeResponse( resp.toXML(), id );
  
}


///////////////////
// STORERESPONSE //
///////////////////#######################################

void DatabaseStorage::storeResponse( std::string xml, string id )
{
  //cout << "Storing response for #" << id << endl;
  stringstream query( stringstream::in | stringstream::out );
  query << "INSERT INTO responses VALUES(" << id << ", $$" << xml << "$$);";
  //cout << query.str() << endl;

  pqxx::work txn(*con);
  txn.exec( query.str() );

  txn.commit();
}


///////////////////
// STORERESPONSE //
///////////////////#######################################

std::string* DatabaseStorage::getResponse( string id )
{

  stringstream query( stringstream::in | stringstream::out );
  query << "SELECT xml FROM responses WHERE id='" << id << "';";

  pqxx::work txn(*con);
  pqxx::result res = txn.exec( query.str() );


  if( res.size() != 1 ){
    return NULL;
  } else {
    string *temp = new string(res[0][0].c_str());
    stringstream del_query( stringstream::in | stringstream::out );
    del_query << "DELETE FROM responses WHERE id='" << id << "';";
    txn.exec( del_query.str() );

    txn.commit();
    return temp;
  }

}
