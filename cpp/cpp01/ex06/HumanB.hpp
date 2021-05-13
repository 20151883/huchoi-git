#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *gun;
    public:
        HumanB(const char *usr_name) :name(usr_name)
        { }
        void setWeapon(Weapon &new_weapon)
        {
            gun = &new_weapon;
        }
        void attack()
        {
            std::cout<<name<<" attacks with his "<<(*gun).getType()<<std::endl;
        }
        
};