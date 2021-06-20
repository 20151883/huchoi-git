#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap(const char *name):Name(name), Hit_point(100), Max_hit_points(100), Energy_points(50), Max_energy_points(50), Level(1), \
									Melee_attack_damage(20), Ranged_attack_damage(15), Armor_damage_reduction(3)
{
	srand(time(NULL));
	std::cout<<"the ScavTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &src):Max_hit_points(100), Max_energy_points(50), \
									Melee_attack_damage(20), Ranged_attack_damage(15), Armor_damage_reduction(3)
{
	Hit_point = src.Hit_point;
	Energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	std::cout<<"the ScavTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}
ScavTrap::~ScavTrap()
{
	std::cout<<"the ScavTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at range, causing <"<<Ranged_attack_damage<<"> points of damage!"<<std::endl;
}


void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at melee, causing <"<<Melee_attack_damage<<"> points of damage!"<<std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (amount >= Armor_damage_reduction)
		amount -= Armor_damage_reduction;
	else
		amount = 0;
	if (Hit_point <= amount)
		Hit_point = amount;
	Hit_point -= amount;
	std::cout<<"FR4G-TP <"<<Name<<"> attacked by someone,and caused <"<<amount<<"> points of damage!"<<std::endl;
	std::cout<<"and your hit point is "<<Hit_point<<std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (amount + Hit_point > Max_hit_points)
		amount = Max_hit_points - Hit_point;
	Hit_point += amount;
	std::cout<<"FR4G-TP <"<<Name<<"> repaired by angel,and repaired <"<<amount<<"> points of hp!"<<std::endl;
	if (Energy_points + amount > Max_energy_points)
		amount = Max_energy_points - Energy_points;
	std::cout<<"FR4G-TP <"<<Name<<"> repaired by angel,and repaired <"<<amount<<"> points of energy point!"<<std::endl;
	std::cout<<"and your hit point is "<<Hit_point<<std::endl;
	std::cout<<"and your Energy point is "<<Energy_points<<std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &src)
{
	Hit_point = src.Hit_point;
	Energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	return (*this);
}

void ScavTrap::challengeNewcomer()
{
	std::string arr[5];
	arr[0] ="MINISHELL is chocolate";
	arr[1] = "libasm is dead";
	arr[2] = "libft is dead";
	arr[3] = "ft_server is client";
	arr[4] = "cub3D is actually 2D";
	if (Energy_points < 25)
		std::cout<<"you have too few ernery to use challengeNewcomer skill!!!!!!!!!!!!!!!!"<<std::endl;
	else
	{
		this->Energy_points -= 25;
		std::cout<<"FR4G-TP <"<<Name<<"> says "<<arr[rand()%5]<<std::endl;
	}
}
