#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#ifndef __NINJATRAP__
#define __NINJATRAP__
class NinjaTrap :public ClapTrap
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
		NinjaTrap(void);
		NinjaTrap(const char *name);
		NinjaTrap(NinjaTrap &src);
		~NinjaTrap();
		NinjaTrap &operator=(NinjaTrap &src);
		void			ninjaShoebox(FragTrap &ref);
		void			ninjaShoebox(ScavTrap &ref);
};
#endif
