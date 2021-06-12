#include "ClapTrap.hpp"

class ScavTrap:virtual public ClapTrap
{
	public:
		ScavTrap(const char *name);
		ScavTrap(const ScavTrap &src);
		~ScavTrap();
		ScavTrap &operator=(ScavTrap &src);
		void	challengeNewcomer(std::string const & target);
};
