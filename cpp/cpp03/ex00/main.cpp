#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap test("huchoi");
	test.attack("enemy");
	test.takeDamage(120);
	test.beRepaired(120);
	return 0;
}
