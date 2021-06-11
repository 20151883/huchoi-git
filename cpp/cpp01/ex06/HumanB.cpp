#include "HumanB.hpp"
void HumanB::setWeapon(Weapon &new_weapon)
{
	gun = &new_weapon;
}
void HumanB::attack()
{
	std::cout<<name<<" attacks with his "<<(*gun).getType()<<std::endl;
}