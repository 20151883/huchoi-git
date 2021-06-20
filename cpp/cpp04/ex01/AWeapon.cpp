#include "AWeapon.hpp"

AWeapon::AWeapon()
{}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
	this->name = name;
	this->apcost = apcost;
	this->damage = damage;
}
AWeapon::AWeapon(const AWeapon &src)
{
	this->name = src.name;
	this->apcost = src.apcost;
	this->damage = src.damage;
}
AWeapon::~AWeapon()
{
	std::cout<<"this is AWeapon's destructor"<<std::endl;
}
AWeapon &AWeapon::operator=(const AWeapon &src)
{
	this->name = src.name;
	this->apcost = src.apcost;
	this->damage = src.damage;
	return *this;
}
std::string AWeapon::getName() const
{
	return this->name;
}
int AWeapon::getAPCost() const
{
	return this->apcost;
}
int AWeapon::getDamage() const
{
	return this->damage;
}
