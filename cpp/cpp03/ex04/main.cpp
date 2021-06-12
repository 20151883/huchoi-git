#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"
#include "ClapTrap.hpp"
#include <typeinfo>
int main()
{
	std::cout << std::endl;

    SuperTrap super("Super");
    ScavTrap scav("Scav");
    NinjaTrap ninj("Ninja");

    super.ninjaShoebox(scav);
    super.ninjaShoebox(ninj);
    super.vaulthunter_dot_exe(ninj.getName());

	std::cout << std::endl;
    return (0);
}
