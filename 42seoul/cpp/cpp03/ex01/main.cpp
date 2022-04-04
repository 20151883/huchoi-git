#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap src("huchoi");
	src.attack("enemy");
	src.takeDamage(111);
	src.beRepaired(111);
	src.guardGate();

	ScavTrap dest = src;
	dest.attack("enemy2");
	dest.takeDamage(222);
	dest.beRepaired(222);
	dest.guardGate();
	return 0;
}
