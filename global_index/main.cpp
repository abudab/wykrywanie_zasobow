#include <iostream>
#include <stdlib.h>
#include <stdio.h>

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

	/*
	std::string str("<Search name='request_001' id='12345'><Filters><Filter name='CPU-Frequency' />"
	     "<Filter name='MEM-Count' /><Filter name='OS-Name' /></Filters><Data><Compare type='OR'>"
	     "<Compare type='AND'><Atrybute name='CPU-Frequency' compType='>=' value='1000' />"
	     "<Atrybute name='CPU-Frequency' compType='<=' value='1500' /></Compare>"
	     "<Atrybute name='MEM-Count' compType='>=' value='4000' /></Compare></Data></Search>");
  
	Search s( str );
	*/

	GlobalCache db = GlobalCache();
        db.setRequest(&s, core.getUID());
      }
    //
    ////////////////////////



    return 0;
}
