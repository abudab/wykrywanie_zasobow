#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <exception>

#include "Net/NetController.h"
#include "XML/Search.h"
#include "db/GlobalCache.hxx"

using std::cout;
using std::endl;

int main(int argc, const char* argv[])
{
    NetController core;

    core.initialize();

    ////////////////////////
    // TUTAJ POWINNA NASTAPIC ODPOWIEDZ
    ////////////////////////
    //

    core.beginHttpHeader(202);

    std::string id, content;

    id = core.idGenerate();
    core.sendURI(core.addrGenerate(id));

    std::string str("POST");
    if(!str.compare(getenv("REQUEST_METHOD")))
    {
        content = core.postContentRead();

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

    if(! content.empty() )
      {
        Search s( content );

        try
        {
            GlobalCache db = GlobalCache(&core);
            db.setRequest(&s, core.getUID());
        }
        catch ( std::exception& e)
        {
            std::cout << "\n...\n" << e.what() << "\n...\n" << std::endl;

        }

      }
    //
    ////////////////////////



    return 0;
}
