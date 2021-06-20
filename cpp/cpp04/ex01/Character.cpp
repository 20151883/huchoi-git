#include "Character.hpp"

Character::Character(std::string const & name) :ap(40),ptr(NULL)
{
	this->name = name;
}
Character::~Character()
{

}
void Character::recoverAP()
{
	this->ap += 10;
	if (this->ap > 40)
		this->ap = 40;
}
void Character::equip(AWeapon* p_src)
{
	this->ptr = p_src;
}
void Character::attack(Enemy*opp)
{
	if (this->ptr)
	{
		if (this->ap - this->ptr->getAPCost() < 0)
			return;
		if (this->ap < this->ptr->getAPCost())
			return;
		std::cout<<this->name<<" attacks "<<opp->getType()<<" with a "<<(this->ptr->getName())<<std::endl;
		this->ptr->attack();
		this->ap -= this->ptr->getAPCost();
		opp->takeDamage(this->ptr->getDamage());
		if (opp->getFlag() == 1)
		{
			opp->~Enemy();
			free(opp);
			opp = NULL;
		}
	}
}
int Character::getAp()
{
	return this->ap;
}
std::string Character::getName() const
{
	return this->name;
}
AWeapon *Character::getWeapon()
{
	return ptr;
}

std::ostream &operator<<(std::ostream &ost, Character &src)
{
	if (src.getWeapon() != NULL)
		printf("%s has %d AP and wields a %s\n", src.getName().c_str(), src.getAp(), src.getWeapon()->getName().c_str());
	else
		printf("%s has %d AP and is unarmed\n", src.getName().c_str(), src.getAp());
	fflush(stdout);
	return ost;
}
