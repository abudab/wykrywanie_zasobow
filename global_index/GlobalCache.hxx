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
#include "QueryDispatcher.hxx"
#include "DatabaseStorage.hxx"
#include "XML/Search.h"
#include "XML/Response.h"

class GlobalCache
{
 public:
   GlobalCache();
  ~GlobalCache();
  void setRequest( const Search* s, unsigned int id );
  Response* getResponse( unsigned int id );
 private:
  QueryDispatcher *qd;
  DatabaseStorage *db;
  Response *resp;
};

#endif // _GLOBALCACHE_H_
