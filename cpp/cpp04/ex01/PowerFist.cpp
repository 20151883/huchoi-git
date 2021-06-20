#include "PowerFist.hpp"

PowerFist::PowerFist() :AWeapon("Power Fist", 8, 50)
{
	this->sound = "* pschhh... SBAM! *";
}
PowerFist::~PowerFist()
{}
PowerFist::PowerFist(PowerFist &src) :AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	this->name =  src.name;
	this->apcost = src.apcost;
	this->damage = src.damage;
	this->sound = src.sound;
}
PowerFist &PowerFist::operator=(PowerFist &src)
{
	this->name =  src.name;
	this->apcost = src.apcost;
	this->damage = src.damage;
	this->sound = src.sound;
	return *this;
}
void	PowerFist::attack() const
{
	std::cout<<this->sound<<std::endl;
}
