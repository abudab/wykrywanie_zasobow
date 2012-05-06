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

    Response* resp = db.getResponse(atoi( core.getUID().c_str() ));

    if( resp )
    {
        core.printHttpHeader(200);

        std::cout << resp->toXML();
    }
    else
        core.printHttpHeader(202);


    return 0;
}
