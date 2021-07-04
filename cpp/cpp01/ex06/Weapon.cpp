#include "Weapon.hpp"

Weapon::Weapon(std::string init) :type(init)
{}
void Weapon::setType(std::string weapon_type)
{
    this->type = weapon_type;
}
const std::string &Weapon::getType()//cpp 참고서 88p
{
    return (type);
}
