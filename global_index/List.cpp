#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Net/NetController.h"
#include "db/GlobalCache.hxx"

int main()
{
    NetController core;
    std::cout<<"Content-type: text/html"<<std::endl<<std::endl;
    core.getContentRead();

    GlobalCache db;

    std::string* resp = db.getResponse( core.getUID().c_str() );

    if( resp )
    {
        core.beginHttpHeader(200);

        std::cout << resp;

        delete resp;
    }
    else
        core.beginHttpHeader(202);

    core.endHttpHeader();

    return 0;
}
