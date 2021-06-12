#ifndef __SUPERTRAP__
# define __SUPERTRAP__

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
class SuperTrap;

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap();
        SuperTrap(std::string name);
        SuperTrap(const SuperTrap&);
        virtual ~SuperTrap();
        SuperTrap &operator=(const SuperTrap& op);
};
#endif
