#include "NetController.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/time.h>


NetController::NetController()
{
    //ctor
}

bool NetController::daemonize()
{
    int i;

    if(getppid()==1) return true; // jestesmy juz demonem ;)

    setsid();
    for ( i=getdtablesize(); i>=0; --i)
        close(i);

    // ustawiamy sobie odpowiednie prawa
    umask(027);

    // ustawiamy sobie odpowiednia pozycje
    chdir("/");

    // odcinamy sie od swiata
    i=fork();

    if (i<0) return false; // system sie wypiol na nasza demonizacje
    if (i>0) return false; // demony nie maja rodzicow

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    return true;

}

void NetController::beginHttpHeader(int status)
{
    std::cout << "Status: " << status;

    if( status == 200 )
        std::cout << " OK\n";
    else if( status == 202 )
        std::cout << " Accepted\n";


}

void NetController::sendURI(std::string uri)
{

    if(uri != "")
        std::cout << "Location: " << uri  << std::endl;
    std::cout << "Content-Type: text/xml\n\n";
    std::cout << uri << std::endl;
}



std::string NetController::postContentRead()
{
    //std::cout <<getenv("CONTENT_LENGTH") << std::endl;

    int size = atoi(getenv("CONTENT_LENGTH"));

    //std::cout <<size<< std::endl;

    char tmp[size+1];

    memset(tmp,0,size+1);

    fread(tmp,1,size,stdin);
    //std::cout <<tmp<< std::endl;
    return tmp;
}

void NetController::getContentRead()
{
    char *value = getenv( "QUERY_STRING" );


    char *tmp =NULL;
    sscanf(value,"id=%as", tmp);

    if( tmp )
        _uid = std::string(tmp);
    else
        _uid = "";
}

std::string NetController::idGenerate()
{
    timeval curtime;
    gettimeofday(&curtime,NULL);

    std::ostringstream stm;
    stm << curtime.tv_sec << curtime.tv_usec ;
    //stm.c_str();
    //std::cout<<curtime<<std::endl;
    _uid =stm.str();
    return _uid;
}

std::string NetController::addrGenerate(std::string id)
{
    std::string adress;

    adress += getenv("SERVER_ADDR");
    adress += "/cgi-bin/List?id=";
    adress += id;

    return adress;
}

bool NetController::initialize()
{
    sleep(0);
    srand(time(NULL));
    sleep(0);
    return true;
}
