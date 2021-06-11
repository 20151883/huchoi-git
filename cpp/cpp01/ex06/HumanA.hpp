#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &gun;
    public:
        HumanA(const char *usr_name, Weapon &test) :name(usr_name), gun(test)
        {}
        void attack();      
};