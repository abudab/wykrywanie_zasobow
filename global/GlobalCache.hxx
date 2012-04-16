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

class GlobalCache
{
 public:
   GlobalCache();
  ~GlobalCache();
  void getData(void);
 private:
  QueryDispatcher *qd;
  DatabaseStorage *db;
};

#endif // _GLOBALCACHE_H_
