#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Net/NetController.h"
#include "db/GlobalCache.hxx"

int main()
{
    NetController core;
    //std::cout<<"Content-type: text/html"<<std::endl<<std::endl;
    core.getContentRead();

    GlobalCache db;

    std::string* resp = db.getResponse( core.getUID().c_str() );

    if( resp )
        core.beginHttpHeader(200);
    else
        core.beginHttpHeader(202);

    core.endHttpHeader();

    if( resp )
    {
        std::cout << *resp;

        delete resp;
    }


    return 0;
}
