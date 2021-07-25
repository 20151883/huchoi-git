#include "FragTrap.hpp"

int main(void)
{
	FragTrap test("huchoi");
	test.attack("enemy");
	test.takeDamage(120);
	test.beRepaired(120);
	test.highFivesGuys();
	
	FragTrap test2(test);
	test.beRepaired(0);
	return 0;
}
