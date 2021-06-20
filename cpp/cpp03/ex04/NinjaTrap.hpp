#include <iostream>
#include <cstring>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#ifndef __NINJATRAP__
#define __NINJATRAP__
class NinjaTrap :virtual public ClapTrap
{
	private:

	public:
		NinjaTrap(void);
		NinjaTrap(const char *name);
		NinjaTrap(NinjaTrap &src);
		virtual ~NinjaTrap();
		NinjaTrap &operator=(NinjaTrap &src);
		void			ninjaShoebox(FragTrap &ref);
		void			ninjaShoebox(ScavTrap &ref);
		void			ninjaShoebox(NinjaTrap &ref);
		void			ninjaShoebox(ClapTrap &ref);
};
#endif
