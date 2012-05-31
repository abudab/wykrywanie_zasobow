#ifndef NETCONTROLLER_H
#define NETCONTROLLER_H

#include <iostream>
#include <cstring>

class NetController
{
    public:
        NetController();


    public:
        bool initialize();
        bool daemonize();
        void beginHttpHeader(int status);
        void sendURI(std::string = "");
        void endHttpHeader(){ std::cout << "Content-Type: text/html\n\n";}
        std::string postContentRead();
        void getContentRead();
        std::string idGenerate();
        std::string addrGenerate(std::string id);


        std::string getUID(void) { return _uid; }




        std::string HttpRequest(std::string adres,std::string message);



    private:

        std::string _request;

        std::string _uid;
};

#endif // NETCONTROLLER_H
