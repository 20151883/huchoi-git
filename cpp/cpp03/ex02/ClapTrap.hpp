#include <iostream>
#include <cstring>
#ifndef _ClapTrap_
#define _ClapTrap_
class ClapTrap{
	protected:
		std::string	Name;
		unsigned int Hit_point;
		unsigned int Max_hit_points;
		unsigned int Energy_points;
		unsigned int Max_energy_points;
		unsigned int Level;
		unsigned int Melee_attack_damage;
		unsigned int Ranged_attack_damage;
		unsigned int Armor_damage_reduction;
	public:
		ClapTrap(void)
		{
			std::cout<<"the ClapTrap is appeared!!!!"<<std::endl;
		}
		ClapTrap(ClapTrap &src)
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
		virtual ~ClapTrap()
		{
			std::cout<<"the ClapTrap is disappeared!!!!"<<std::endl;
		}
		virtual ClapTrap &operator=(ClapTrap &src)
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
		 void	rangedAttack(std::string const & target);
		 void	meleeAttack(std::string const & target);
		 void	takeDamage(unsigned int amount);
		 void	beRepaired(unsigned int amount);
};
#endif
