#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout<<"the void ClapTrap constucture is called!!!!"<<std::endl;
}

ClapTrap::ClapTrap(const char *name): Name(name), Hit_points(10), Energy_points(10), Attack_Damage(0)
{
	std::cout<<"the ClapTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
	Hit_points = src.Hit_points;
	Energy_points = src.Energy_points;
	Attack_Damage = src.Attack_Damage;
	Name = src.Name;
	return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
	std::cout<<"the ClapTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout<<"the ClapTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout<<"ClapTrap <"<<this->Name<<"> attacks <"<<target<<">, causing <"<<this->Attack_Damage<<"> points of damage!"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (Hit_points <= amount)
		Hit_points = amount;
	Hit_points -= amount;
	std::cout<<Name<<"> attacked by someone,and caused <"<<amount<<"> points of damage!"<<std::endl;
	std::cout<<"and your hit point is "<<Hit_points<<std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (Hit_points > Hit_points + amount)
		Hit_points = 0xFFFFFFFF;
	else
		Hit_points += amount;
	std::cout<<Name<<"> repaired by angel,and repaired <"<<amount<<"> points of hp!"<<std::endl;
	if (Energy_points > Energy_points + amount)
		Energy_points = 0xFFFFFFFF;
	else
		Energy_points += amount;
	std::cout<<Name<<"> repaired by angel,and repaired <"<<amount<<"> points of energy point!"<<std::endl;
	std::cout<<"and your hit point is "<<Hit_points<<std::endl;
	std::cout<<"and your Energy point is "<<Energy_points<<std::endl;
}


