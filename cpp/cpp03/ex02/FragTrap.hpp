#ifndef FragTRAP_HPP
# define FragTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(const char *name = "non name");
		FragTrap &operator=(const FragTrap &src);
		FragTrap(const FragTrap &src);
		~FragTrap();
		void highFivesGuys(void);
		void attack(std::string const & target);
};

#endif
