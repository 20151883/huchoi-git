#include "FragTrap.hpp"
#include "ScavTrap.hpp"
int main(void)
{
	FragTrap test("test");
	test.rangedAttack("enemy-1");
	test.meleeAttack("enemy-2");
	test.takeDamage(120);
	test.beRepaired(120);
	test.vaulthunter_dot_exe("enemy-3");
	std::cout<<"********************************"<<std::endl;
	ScavTrap var("var");
	var.rangedAttack("opponent-1");
	var.meleeAttack("opponent-2");
	var.takeDamage(120);
	var.beRepaired(120);
	var.challengeNewcomer("opponent-3");
	var.challengeNewcomer("opponent-3");
	var.challengeNewcomer("opponent-3");
	return 0;
}
