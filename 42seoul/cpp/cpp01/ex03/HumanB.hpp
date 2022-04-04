#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *gun;
    public:
        HumanB(const char *usr_name="non name") :name(usr_name){}
        void setWeapon(Weapon &new_weapon);
        void attack();
};

#endif
