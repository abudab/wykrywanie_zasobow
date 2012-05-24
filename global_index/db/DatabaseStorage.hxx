/*

    #################################################################
    # 								    #
    # ⌬ NAME:		C++ TEMPLATE CLASS			    #
    # ⌬ AUTHOR:	A. JANUSZ				    #
    # ⌬ DESC:		HEADER FILE				    #
    #								    #
    #   ⌬      FACULTY OF PHYSICS AND COMPUTER SCIENCE       ⌬     #
    #   ⌬  UNIVERSITY OF SCIENCE AND TECHNOLOGY AGH, CRACOW  ⌬     #
    # 								    #
    #################################################################

*/

#ifndef _DATABASESTORAGE_H_
#define _DATABASESTORAGE_H_


#include <cstdio>
#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include "../XML/Response.h"
#include "../XML/Monitor.h"
#include "../XML/Atribute.h"

class DatabaseStorage
{
 public:
  DatabaseStorage( const char* host, const char* user, const char* pass, const char* port );
  ~DatabaseStorage();

  void getData( const char* sql_query, std::string id );
  std::string* getResponse( std::string id );
 private:
  pqxx::connection *con;

  void storeResponse( std::string xml, std::string id );
};

#endif // _DATABASESTORAGE_H_
