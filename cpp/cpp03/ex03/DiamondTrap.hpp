#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :public FragTrap, public ScavTrap
{
	private:
		std::string Name;
		DiamondTrap();
	public:
		DiamondTrap(const char *name);
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap &operator=(const DiamondTrap &src);
		virtual ~DiamondTrap();
		void whoAmI();
		virtual void attack(std::string const & target);
};

#endif
