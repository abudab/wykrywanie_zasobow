#include "NetController.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>


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

void NetController::printHttpHeader(int status)
{
    std::cout << "HTTP/1.1 " << status << "\n";
    std::cout << "Content-Type: text/html\n";

}
