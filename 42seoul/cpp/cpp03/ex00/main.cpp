#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap src("huchoi");
	src.attack("enemy1");
	src.takeDamage(111);
	src.beRepaired(111);

	ClapTrap obj = src;
	obj.attack("enemy2");
	obj.takeDamage(222);
	obj.beRepaired(222);
	return 0;
}
