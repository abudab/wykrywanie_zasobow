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

#ifndef _GLOBALCACHE_H_
#define _GLOBALCACHE_H_


#include <cstdio>
#include <typeinfo>
#include <boost/regex.hpp>
#include "QueryDispatcher.hxx"
#include "DatabaseStorage.hxx"
#include "../XML/Search.h"
#include "../XML/Response.h"
#include "../Net/NetController.h"

class GlobalCache
{
 public:
   GlobalCache( NetController *net );
  ~GlobalCache();
  void setRequest( Search* s, std::string id );
  std::string* getResponse( std::string id );
 private:
  NetController *net;
  QueryDispatcher *qd;
  DatabaseStorage *db;
  Response *resp;

  void saveRequest( std::string id, std::string data );
  std::pair<std::string,std::string>*  getRequest( void );

  void registerLocalIndex( std::string url );
  void deleteLocalIndex( std::string url );
  bool update( void );

  void walkTree( Info *i, std::vector <std::string> *sv );
  std::string validate( std::string text, const char* regex );
  std::string quote( std::string text );
};

#endif // _GLOBALCACHE_H_
