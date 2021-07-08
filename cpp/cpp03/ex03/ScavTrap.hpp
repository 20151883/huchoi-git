#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		ScavTrap();
		int gate_keeper_flag;
	public:
		ScavTrap(const char *name);
		ScavTrap &operator=(const ScavTrap &src);
		ScavTrap(const ScavTrap &src);
		virtual ~ScavTrap();
		void guardGate();
		virtual void attack(std::string const & target);
};

#endif
