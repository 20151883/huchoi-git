#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
:
    ClapTrap(),
    FragTrap(),
    NinjaTrap()
{}

SuperTrap::SuperTrap(const char *name)
:
    ClapTrap(
        100,
        10,
        120,
        120,
        1,
        name,
        60,
        30,
        5
    ),
    FragTrap(name),
    NinjaTrap(name)
{
    std::cout << "Super Trap created" << std::endl;
}

/*SuperTrap::SuperTrap(const SuperTrap& op)
:
    ClapTrap(op)
{
    std::cout << "Super Trap Copied !" << std::endl;
}*/

SuperTrap::~SuperTrap()
{
    std::cout << "Super Trap Destroyed !" << std::endl;
}

//SuperTrap & SuperTrap::operator=(const SuperTrap& op)
//{
 //   if (this == &op)
//        return (*this);
//    ClapTrap::operator=(op);
//    return (*this);
//}
