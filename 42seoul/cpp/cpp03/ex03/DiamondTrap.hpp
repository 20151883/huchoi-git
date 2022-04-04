#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :public FragTrap, public ScavTrap
{
	private:
		std::string Name;
	public:
		DiamondTrap(const char *name = "non name");
		DiamondTrap(const DiamondTrap &src);
		DiamondTrap &operator=(const DiamondTrap &src);
		~DiamondTrap();
		void whoAmI();
		void attack(std::string const & target);
};

#endif
