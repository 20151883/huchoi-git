#include "ClapTrap.hpp"
ClapTrap::ClapTrap(void)
{
	std::cout<<"the ClapTrap's constructor!!!!"<<std::endl;
}
ClapTrap::ClapTrap(ClapTrap &src)
{
	Hit_point = src.Hit_point;
	Max_hit_points = src.Max_hit_points;
	Energy_points = src.Energy_points;
	Max_energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	Melee_attack_damage = src.Melee_attack_damage;
	Ranged_attack_damage = src.Ranged_attack_damage;
	Armor_damage_reduction = src.Armor_damage_reduction;
}
 ClapTrap::~ClapTrap()
{
	std::cout<<"the ClapTrap's destructor!!!!"<<std::endl;
}
 ClapTrap &ClapTrap::operator=(ClapTrap &src)
{
	Hit_point = src.Hit_point;
	Max_hit_points = src.Max_hit_points;
	Energy_points = src.Energy_points;
	Max_energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	Melee_attack_damage = src.Melee_attack_damage;
	Ranged_attack_damage = src.Ranged_attack_damage;
	Armor_damage_reduction = src.Armor_damage_reduction;
	return (*this);
}
void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at range, causing <"<<Ranged_attack_damage<<"> points of damage!"<<std::endl;
}


void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at melee, causing <"<<Melee_attack_damage<<"> points of damage!"<<std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
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

void	ClapTrap::beRepaired(unsigned int amount)
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

