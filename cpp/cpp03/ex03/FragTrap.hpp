#ifndef FragTRAP_HPP
# define FragTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		FragTrap();
	public:
		FragTrap(const char *name);
		FragTrap &operator=(const FragTrap &src);
		FragTrap(const FragTrap &src);
		virtual ~FragTrap();
		void highFivesGuys(void);
		virtual void attack(std::string const & target);
};

#endif
