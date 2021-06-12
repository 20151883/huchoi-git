#include "FragTrap.hpp"

int main(void)
{
	FragTrap test("test");
	test.rangedAttack("enemy-1");
	test.meleeAttack("enemy-2");
	test.takeDamage(120);
	test.beRepaired(120);
	test.vaulthunter_dot_exe("enemy-3");
	return 0;
}
