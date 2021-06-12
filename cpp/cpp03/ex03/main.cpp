#include "NinjaTrap.hpp"


int main(void)
{
	NinjaTrap ninja("ninja");
	FragTrap test("test");
	ScavTrap test1("test1");
	ninja.ninjaShoebox(test);
	ninja.ninjaShoebox(test1);
	return (0);
}
