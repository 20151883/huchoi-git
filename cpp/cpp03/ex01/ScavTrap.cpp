#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout<<"the void ScavTrap constucture is called!!!!"<<std::endl;
}

ScavTrap::ScavTrap(const char *name): ClapTrap()//, Name(name), Hit_points(100), Energy_points(50), Attack_Damage(20)
{
	this->Name = name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_Damage = 20;
	std::cout<<"the ScavTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_Damage = src.Attack_Damage;
	Name = src.Name;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &src):ClapTrap()
{
	*this = src;
	std::cout<<"the ScavTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"the ScavTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

void ScavTrap::guardGate()
{
	std::cout<<"ScavTrap have enterred in Gate keeper mode."<<std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout<<"ScavTrap <"<<this->Name<<"> attacks <"<<target<<">, causing <"<<this->Attack_Damage<<"> points of damage!"<<std::endl;
}
