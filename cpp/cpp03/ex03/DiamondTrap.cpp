#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const char *name):FragTrap(), ScavTrap()
{
	Hit_points = 100;
	Energy_points = 50;
	Attack_Damage = 30;
	Name = name;
	ClapTrap::Name = std::string(name) + std::string("_clap_name");
}

DiamondTrap::DiamondTrap(const DiamondTrap &src):FragTrap(), ScavTrap()
{
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_Damage = src.Attack_Damage;
	Name = src.Name;
	ClapTrap::Name = std::string(src.Name) + std::string("_clap_name");
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout<<"the DiamondTrap("<<this->Name<<") is disappeared!!!!"<<std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout<<this->Name<<"     "<<ClapTrap::Name<<std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	//std::cout<<"ScavTrap <"<<this->Name<<"> attacks <"<<target<<">, causing <"<<this->Attack_Damage<<"> points of damage!"<<std::endl;
	std::cout<<"ScavTrap <"<<ScavTrap::Name<<"> attacks <"<<target<<">, causing <"<<20<<"> points of damage!"<<std::endl;
}
