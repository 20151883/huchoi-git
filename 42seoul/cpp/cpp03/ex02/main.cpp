#include "FragTrap.hpp"

int main(void)
{
	FragTrap test("huchoi");
	test.attack("enemy");
	test.takeDamage(120);
	test.beRepaired(120);
	test.highFivesGuys();
	
	FragTrap test2(test);
	return 0;
}
