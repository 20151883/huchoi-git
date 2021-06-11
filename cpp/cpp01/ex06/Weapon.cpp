#include "Weapon.hpp"

Weapon::Weapon(std::string init) :type(init)
{}
void Weapon::setType(std::string weapon_type)
{
    this->type = weapon_type;
}
std::string Weapon::getType()
{
    return (type);
}