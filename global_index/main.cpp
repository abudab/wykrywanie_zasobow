#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <exception>

#include "Net/NetController.h"
#include "XML/Search.h"
#include "db/GlobalCache.hxx"

#include <fstream>

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



        //std::cout << core.addrGenerate(id)<<std::endl;
        core.sendURI(core.addrGenerate(id));

    std::string str("POST");
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
	Search s( content );
	
	try
	  {
	    GlobalCache db = GlobalCache(&core);
	    db.setRequest(&s, core.getUID());
	  }
	catch( std::exception& e)
	  {
	    std::ofstream log;
	    log.open("/home/bitnami/index.log");
	    log << "\n...\n" << e.what() << "\n...\n"<< std::endl;
	    log.close();
	  }
      }
    //
    ////////////////////////



    return 0;
}
