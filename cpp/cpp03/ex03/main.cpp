#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap test("huchoi");
	test.attack("enemy");
	test.takeDamage(120);
	test.beRepaired(120);
	test.highFivesGuys();
	test.whoAmI();
	test.attack("test");

	//DiamondTrap test2(test);
	return 0;
}
