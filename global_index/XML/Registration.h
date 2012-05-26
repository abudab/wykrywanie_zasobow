#ifndef REGISTRATION_H
#define REGISTRATION_H
/////////////////////////////////////////////////////////
/// \file Registration
/// \author Monika Godzwon
/// \brief  klasa Registration mająca pomagać przy rejestracji indeksów lokalnych
///////////////////////////////////////////////////////

#include "../pugi/pugixml.hpp"
#include <string>
using namespace std;
class Registration
{
    public:
        Registration();
        Registration(std::string xml);
        string Getaddress() { return _address; }
        void Setaddress(string val) { _address = val; }

    private:
        string _address;
};

#endif // REGISTRATION_H
