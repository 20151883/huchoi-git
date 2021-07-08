#include "Character.hpp"

Character::Character()
{}

Character::Character(std::string const & name) :ap(40),ptr(NULL)
{
	this->name = name;
}
Character::~Character()
{
}

Character &operator=(const Character &src)
{

}

Character(const Character &src)
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
	if (p_src == NULL)
		return ;
	this->ptr = p_src;
}
void Character::attack(const Enemy*opp)
{
	if (opp == NULL)
		return ;
	if (this->ptr)
	{
		if (this->ap - this->ptr->getAPCost() < 0)
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
int Character::getAp() const
{
	return this->ap;
}

const std::string Character::getName() const
{
	return this->name;
}

const AWeapon *Character::getWeapon() const
{
	return ptr;
}

std::ostream &operator<<(std::ostream &ost, Character &src)
{
	if (src.getWeapon() != NULL)
		ost<<src.getName()<<" has "<<src.getAp()<<" AP and wields a "<<src.getWeapon()->getName()<<"\n";
	else
		ost<<src.getName()<<" has "<<src.getAp()<<" AP and is unarmed\n";
	ost.flush();
	return ost;
}
