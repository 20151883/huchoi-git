#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstring>

class ClapTrap{
	protected:
		std::string Name;
		unsigned int Hit_points;
		unsigned int Energy_points;
		unsigned int Attack_Damage;
		ClapTrap();
	public:
		ClapTrap(const char *name);
		ClapTrap(const ClapTrap &src);
		virtual ~ClapTrap();
		ClapTrap &operator=(const ClapTrap &src);
		virtual void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
#endif
