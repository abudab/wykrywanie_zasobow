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

class DatabaseStorage
{
 public:
  DatabaseStorage( const char* host, const char* user, const char* pass, const char* port );
  ~DatabaseStorage();

  void getData( const char* sql_query );
 private:
  pqxx::connection *con;
};

#endif // _DATABASESTORAGE_H_
