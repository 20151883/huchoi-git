#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const char *name):ClapTrap((std::string(name) + std::string("_clap_name")).c_str()), FragTrap((std::string(name) + std::string("_clap_name"))), ScavTrap((std::string(name) + std::string("_clap_name")))
{
	Hit_points = FragTrap::Hit_points;
	Energy_points = ScavTrap::Energy_points;
	Attack_Damage = FragTrap::Attack_Damage;
	Name = name;
	ClapTrap::Name = std::string(name) + std::string("_clap_name");
	std::cout<<"the DiamondTrap("<<this->Name<< ") is appeared!!!!"<<std::endl;
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
	std::cout<<"my name is "<<this->Name<<"   and   ClapTrap name is "<<ClapTrap::Name<<std::endl;
}

void DiamondTrap::attack(std::string const & target)
{
	ScavTrap::attack(target);
}
