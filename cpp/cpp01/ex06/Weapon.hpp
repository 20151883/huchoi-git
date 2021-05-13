#include <iostream>
#ifndef _Weapon_
#define _Weapon_
class Weapon
{
    private:
        std::string type;
    public:
        /*Weapon()
        {}*/
        Weapon(std::string init) :type(init)
        {}
        void setType(std::string weapon_type)
        {
            type = weapon_type;
        }
        std::string getType()
        {
            return (type);
        }
};
#endif