#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <exception>

#include "Net/NetController.h"
#include "XML/Registration.h"
#include "db/GlobalCache.hxx"

int main(int argc, const char* argv[])
{
    NetController core;

    core.initialize();

    ////////////////////////
    // TUTAJ POWINNA NASTAPIC ODPOWIEDZ
    ////////////////////////
    //

    core.beginHttpHeader(200);
    core.endHttpHeader();


    std::string str("POST");
    std::string content;


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
        Registration r( content );

        //TODO; Olek to powinno trafic do bazy danych, to jest adres lokalnego indeksu
        //r.Getaddress();
      }
    //
    ////////////////////////



    return 0;
}
