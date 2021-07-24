#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const char *name): ClapTrap(name), gate_keeper_flag(0)
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
	gate_keeper_flag = src.gate_keeper_flag;
	return (*this);
}

ScavTrap::ScavTrap(const ScavTrap &src):ClapTrap()
{
	*this = src;
	std::cout<<"the ScavTrap( "<<Name<< ") is appeared!!!!"<<std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout<<"the ScavTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

void ScavTrap::guardGate()
{
	if (gate_keeper_flag == 0)
	{
		std::cout<<"ScavTrap have enterred in Gate keeper mode."<<std::endl;
		gate_keeper_flag = 1;
	}
	else
		std::cout<<"ScavTrap have already enterred in Gate keeper mode."<<std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	std::cout<<"ScavTrap <"<<this->Name<<"> attacks <"<<target<<">, causing <"<<this->Attack_Damage<<"> points of damage!"<<std::endl;
}
