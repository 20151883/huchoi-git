#include "ClapTrap.hpp"
#ifndef __SCAVTRAP__
#define __SCAVTRAP__
class ScavTrap:public ClapTrap
{
	public:
		ScavTrap(const char *name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap &src);
		void	challengeNewcomer();
};
#endif
