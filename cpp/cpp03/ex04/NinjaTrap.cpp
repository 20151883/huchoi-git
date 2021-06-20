#include "NinjaTrap.hpp"
#include "FragTrap.hpp"
NinjaTrap::NinjaTrap(void)
{std::cout<<"the NinjaTrap (NULL) is appeared!!!!"<<std::endl;}

NinjaTrap::NinjaTrap(const char *name)
{
	Name = name;
	Hit_point = 60;
	Max_hit_points= 60;
	Energy_points=120;
	Max_energy_points = 120;
	Level = 1;
	Melee_attack_damage = 60;
	Ranged_attack_damage = 5;
	Armor_damage_reduction = 0;
	std::cout<<"the NinjaTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap &src)
{
	Max_hit_points= 60;
	Max_energy_points = 120;
	Melee_attack_damage = 60;
	Ranged_attack_damage = 5;
	Armor_damage_reduction = 0;
	Hit_point = src.Hit_point;
	Energy_points = src.Energy_points;
	Level = src.Level;
	Name = src.Name;
	std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout<<"the NinjaTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
}

NinjaTrap &NinjaTrap::operator=(NinjaTrap &src)
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

void	NinjaTrap::ninjaShoebox(FragTrap &ref)
{
	ref.vaulthunter_dot_exe("enemy1");
}
void	NinjaTrap::ninjaShoebox(ScavTrap &ref)
{
	ref.challengeNewcomer();
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &ref)
{
	std::cout<<"this is "<<ref.Name<<"ninjaTrap class and Ninjashoebox is called"<<std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap &ref)
{
	std::cout<<"this is "<<ref.getName()<<"ClapTrap class and Ninjashoebox is called"<<std::endl;
}
