#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name)//, Name(name), Hit_points(100), Energy_points(50), Attack_Damage(20)
{
	this->Name = name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_Damage = 30;
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_Damage = src.Attack_Damage;
	Name = src.Name;
	return (*this);
}

FragTrap::FragTrap(const FragTrap &src):ClapTrap()
{
	*this = src;
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<"the FragTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout<<"*******************************"<<std::endl;
	std::cout<<"*this is positive five request*"<<std::endl;
	std::cout<<"*******************************"<<std::endl;
	std::cout<<"I Am Rubber, You Are Glue"<<std::endl;
	std::cout<<"Start with a Bang"<<std::endl;
	std::cout<<"You're...GOING TO LOVE ME!!"<<std::endl;
	std::cout<<"Kick Him While He's Up"<<std::endl;
	std::cout<<"Through Thick and Thin"<<std::endl;
}

void FragTrap::attack(std::string const & target)
{
	std::cout<<"FragTrap <"<<this->Name<<"> attacks <"<<target<<">, causing <"<<this->Attack_Damage<<"> points of damage!"<<std::endl;
}
