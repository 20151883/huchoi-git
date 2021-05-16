#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"
class FragTrap :public ClapTrap
{
	private:
		unsigned int Hit_point;
		unsigned int Max_hit_points;
		unsigned int Energy_points;
		unsigned int Max_energy_points;
		unsigned int Level;
		std::string Name;
		unsigned int Melee_attack_damage;
		unsigned int Ranged_attack_damage;
		unsigned int Armor_damage_reduction;
	public:
		FragTrap(void)
		{ std::cout<<"the FragTrap (NULL) is appeared!!!!"<<std::endl;}
		FragTrap(const char *name):Name(name), Hit_point(100), Max_hit_points(100), Energy_points(100), Max_energy_points(100), Level(1), \
									Melee_attack_damage(30), Ranged_attack_damage(20), Armor_damage_reduction(5)
		{
			std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
		}
		~FragTrap()
		{
			std::cout<<"the FragTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
		}
		FragTrap &operator=(FragTrap &src)
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
		virtual void	rangedAttack(std::string const & target);
		virtual void	meleeAttack(std::string const & target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
};
