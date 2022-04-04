#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		int gate_keeper_flag;
	public:
		ScavTrap(const char *name = "non name");
		ScavTrap &operator=(const ScavTrap &src);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		void guardGate();
		void attack(std::string const & target);
};

#endif
