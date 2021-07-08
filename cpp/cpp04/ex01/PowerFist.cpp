#include "PowerFist.hpp"

PowerFist::PowerFist() :AWeapon("Power Fist", 8, 50)
{
	this->sound = "* pschhh... SBAM! *";
}

PowerFist::~PowerFist()
{}

PowerFist::PowerFist(const PowerFist &src) :AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	*this = src;
}

PowerFist &PowerFist::operator=(const PowerFist &src)
{
	this->name =  src.getName();
	this->apcost = src.getAPCost();
	this->damage = src.getDamage();
	this->sound = "* pschhh... SBAM! *";
	return *this;
}

void	PowerFist::attack() const
{
	std::cout<<this->sound<<std::endl;
}
