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
#include <curl/curl.h>
#include <curl/easy.h>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>

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
    int size = strlen(value);
    char tmp[size];

    //char tmp[1000]={0};
    //char tmp[1000]={0};

    sscanf(value,"id=%s", tmp);
    _uid = tmp;

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

std::string NetController::HttpRequest(std::string adres,std::string message)
{

    std::stringstream out;

    try
	{
		curlpp::Cleanup cleaner;
    curlpp::Easy request;

    request.setOpt(new curlpp::options::Url(adres));
    request.setOpt(new curlpp::options::Verbose(true));

    std::list<std::string> header;
    header.push_back("Content-Type: text/xml");

    request.setOpt(new curlpp::options::HttpHeader(header));

    request.setOpt(new curlpp::options::PostFields(message));
    request.setOpt(new curlpp::options::PostFieldSize(message.length()));

    request.perform();



    out <<request;

	}
catch ( curlpp::LogicError & e ) {
    //std::cout << e.what() << std::endl;
  }
  catch ( curlpp::RuntimeError & e ) {
    //std::cout << e.what() << std::endl;
  }

  return out.str();
  }



