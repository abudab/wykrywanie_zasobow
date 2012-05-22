#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Net/NetController.h"
#include "XML/Search.h"
#include "db/GlobalCache.hxx"


int main(int argc, const char* argv[])
{
    NetController core;

    core.initialize();

    ////////////////////////
    // TUTAJ POWINNA NASTAPIC ODPOWIEDZ
    ////////////////////////
    //

    core.beginHttpHeader(202);

    std::string id;
        id = core.idGenerate();



        //std::cout << core.addrGenerate(id)<<std::endl;
        core.sendURI(core.addrGenerate(id));

    std::string str("POST");
    if(!str.compare(getenv("REQUEST_METHOD")))
    {
        core.postContentRead();

    }

    //
    ////////////////////////

    ////////////////////////
    // KONCZYMY KOMUNIKACJE Z KLIENTEM PRZEZ DEMONIZACJE PROCESU
    ////////////////////////
    //
    if( !core.daemonize() )
        std::cout << "demonizacja sie nie udala\n";



    //
    ////////////////////////

    ////////////////////////
    // TUTAJ PZRETWARZAMY ZAPYTANIE W CELU WYGENEROWANIA WYNIKOW
    ////////////////////////
    //
        Search s( core.postContentRead() );
        GlobalCache db;
        db.setRequest(&s, core.getUID());
    //
    ////////////////////////



    return 0;
}
