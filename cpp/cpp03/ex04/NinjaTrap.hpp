#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"

class NinjaTrap :public ClapTrap
{
	public:
		NinjaTrap(void)
		{std::cout<<"the NinjaTrap (NULL) is appeared!!!!"<<std::endl;}
		NinjaTrap(const char *name):Name(name), Hit_point(60), Max_hit_points(60), Energy_points(120), Max_energy_points(120), Level(1), \
									Melee_attack_damage(60), Ranged_attack_damage(5), Armor_damage_reduction(0)
		{
			std::cout<<"the NinjaTrap("<<Name<< ") is appeared!!!!"<<std::endl;
		}
		~NinjaTrap()
		{
			std::cout<<"the NinjaTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
		}
		NinjaTrap &operator=(NinjaTrap &src)
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
