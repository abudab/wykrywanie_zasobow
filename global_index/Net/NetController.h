#ifndef NETCONTROLLER_H
#define NETCONTROLLER_H

#include <iostream>
#include <cstring>

class NetController
{
    public:
        NetController();


    public:
        bool daemonize();
        void printHttpHeader(int status);
    private:

        int _uid;
};

#endif // NETCONTROLLER_H
