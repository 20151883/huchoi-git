#include <iostream>
#include <cstring>

class ScavTrap{
	private:
		std::string Name;
		unsigned int Hit_point;
		const unsigned int Max_hit_points;
		unsigned int Energy_points;
		const unsigned int Max_energy_points;
		unsigned int Level;
		const unsigned int Melee_attack_damage;
		const unsigned int Ranged_attack_damage;
		const unsigned int Armor_damage_reduction;
	public:
		ScavTrap(const char *name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap &src);
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	challengeNewcomer();
};
