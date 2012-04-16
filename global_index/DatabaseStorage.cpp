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

/////////////////
// CONSTRUCTOR //
/////////////////#######################################

DatabaseStorage::DatabaseStorage(const char* host, const char* user, const char* pass, const char* port )
{
  cout << "Creating DatabaseStorage" << endl;

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
  cout << "Deleting DatabaseStorage" << endl;

  delete(con);
}


/////////////
// GETDATA //
/////////////#######################################

void DatabaseStorage::getData( const char* sql_query )
{

  cout << "DATABASE: " << sql_query << endl;

  pqxx::work txn(*con);
  pqxx::result res = txn.exec( sql_query );

  txn.commit();
  
}
