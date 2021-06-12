#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap(const char *name):ClapTrap()
{
	Name = name;
	Hit_point = 100;
	Max_hit_points= 100;
	Energy_points=100;
	Max_energy_points = 100;
	Level = 1;
	Melee_attack_damage = 30;
	Ranged_attack_damage = 20;
	Armor_damage_reduction = 5;
	srand(time(NULL));
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}
FragTrap::FragTrap(void)
{
	Name = "no name";
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}
FragTrap::FragTrap(const FragTrap &src):ClapTrap()
{
	Max_hit_points= 100;
	Max_energy_points = 100;
	Melee_attack_damage = 30;
	Ranged_attack_damage = 20;
	Armor_damage_reduction = 5;
	Hit_point = src.Hit_point;
	Energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

FragTrap::~FragTrap()
{
	std::cout<<"the FragTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &src)
{
	Hit_point = src.Hit_point;
	Energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	return (*this);
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string arr[5];
	arr[0] ="Miniontrap";
	arr[1] = "Meat unicycle";
	arr[2] = "Funzerker";
	arr[3] = "Mechomagician";
	arr[4] = "Shhhh....trap";
	if (Energy_points < 25)
		std::cout<<"you have too few ernery to use vaulthunter_dot_exe skill"<<std::endl;
	else
	{
		this->Energy_points -= 25;
		std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at "<<arr[rand()%5]<<", causing <"<<25<<"> points of damage!"<<std::endl;
	}
}
