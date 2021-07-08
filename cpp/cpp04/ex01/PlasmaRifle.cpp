#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() :AWeapon("Plasma Rifle", 5, 21)
{
	this->sound =  "* piouuu piouuu piouuu *";
}

PlasmaRifle::~PlasmaRifle()
{}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &src) :AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	this->sound = src.sound;
}

PlasmaRifle &PlasmaRifle::operator=(const PlasmaRifle &src)
{
	this->name =  src.getName();
	this->apcost = src.getAPCost();
	this->damage = src.getDamage();
	this->sound = "* piouuu piouuu piouuu *";
	return *this;
}

void	PlasmaRifle::attack() const
{
	std::cout<<this->sound<<std::endl;
}
