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
    // TUTAJ PZRETWARZAMY ZAPYTANIE W CELU WYGENEROWANIA WYNIKOW
    ////////////////////////
    //

    if(! content.empty() )
      {
	try
	  {
	    Registration r( content );
	    GlobalCache db(&core);
	    
	    //TODO; Olek to powinno trafic do bazy danych, to jest adres lokalnego indeksu
	    //r.Getaddress();
	    db.registerLocalIndex( r.Getaddress() );
	  }
	catch( exception& e)
	  {
	    
	  }
      }
    //
    ////////////////////////
    


    return 0;
}
