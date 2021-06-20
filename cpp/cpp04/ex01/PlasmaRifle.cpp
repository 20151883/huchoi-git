#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :AWeapon("Plasma Rifle", 5, 21)
{
	this->sound =  "* piouuu piouuu piouuu *";
}

PlasmaRifle::~PlasmaRifle()
{}

PlasmaRifle::PlasmaRifle(PlasmaRifle &src) :AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	this->sound = src.sound;
}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle &src)
{
	this->name =  src.name;
	this->apcost = src.apcost;
	this->damage = src.damage;
	this->sound = src.sound;
	return *this;
}

void	PlasmaRifle::attack() const
{
	std::cout<<this->sound<<std::endl;
}
