#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap test("huchoi");
	test.attack("enemy");
	test.takeDamage(120);
	test.beRepaired(120);
	test.guardGate();
	return 0;
}
