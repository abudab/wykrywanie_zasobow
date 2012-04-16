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

#ifndef _QUERYDISPATCHER_H_
#define _QUERYDISPATCHER_H_


#include <cstdio>
#include <string>
#include <iostream>

class QueryDispatcher
{
 public:
   QueryDispatcher();
  ~QueryDispatcher();
  
  const char* dispatch( const char* query ) const;
 private:

};

#endif // _QUERYDISPATCHER_H_
