#include "ClapTrap.hpp"
#ifndef __FRAGTRAP__
#define __FRAGTRAP__
class FragTrap:virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const char *name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap &operator=(FragTrap &src);
		void	vaulthunter_dot_exe(std::string const & target);
};
#endif
