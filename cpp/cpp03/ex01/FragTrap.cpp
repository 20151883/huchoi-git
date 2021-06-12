#include "FragTrap.hpp"
#include <ctime>

FragTrap::FragTrap(const char *name): Name(name), Hit_point(100), Max_hit_points(100), Energy_points(100), Max_energy_points(100), Level(1), \
									Melee_attack_damage(30), Ranged_attack_damage(20), Armor_damage_reduction(5)
{
	srand(time(NULL));
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap &src):Max_hit_points(100), Max_energy_points(100), \
									Melee_attack_damage(30), Ranged_attack_damage(20), Armor_damage_reduction(5)
{
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

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at range, causing <"<<Ranged_attack_damage<<"> points of damage!"<<std::endl;
}


void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at melee, causing <"<<Melee_attack_damage<<"> points of damage!"<<std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::beRepaired(unsigned int amount)
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
