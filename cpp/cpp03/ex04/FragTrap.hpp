#ifndef __FRAGTRAP__
#define __FRAGTRAP__
# include "ClapTrap.hpp"
class FragTrap:virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const char *name);
		FragTrap(const FragTrap &src);
		virtual ~FragTrap();
		FragTrap &operator=(FragTrap &src);
		void	vaulthunter_dot_exe(std::string const & target);
};
#endif
