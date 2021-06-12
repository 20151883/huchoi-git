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
		ClapTrap();
		ClapTrap(unsigned int, unsigned int, unsigned int,unsigned int,unsigned int,const char *,unsigned int,unsigned int,unsigned int);
		ClapTrap(ClapTrap &src);
		virtual ~ClapTrap();
		virtual ClapTrap &operator=(ClapTrap &src);
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
#endif
