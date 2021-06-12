#include "ScavTrap.hpp"
#include <ctime>

ScavTrap::ScavTrap(const char *name):ClapTrap()
{
	srand(time(NULL));
	Name = name;
	Hit_point = 100;
	Max_hit_points= 100;
	Energy_points=50;
	Max_energy_points = 50;
	Level = 1;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 15;
	Armor_damage_reduction = 3;
	std::cout<<"the ScavTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src):ClapTrap()
{
	Max_hit_points= 100;
	Max_energy_points = 50;
	Melee_attack_damage = 20;
	Ranged_attack_damage = 15;
	Armor_damage_reduction = 3;
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

ScavTrap &ScavTrap::operator=(ScavTrap &src)
{
	Hit_point = src.Hit_point;
	Energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	return (*this);
}

void ScavTrap::challengeNewcomer(std::string const & target)
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
		std::cout<<"FR4G-TP <"<<Name<<"> says "<<arr[rand()%5]<<" to "<<target<<", causing a fun....."<<std::endl;
	}
}
