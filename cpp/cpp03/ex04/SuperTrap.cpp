#include "SuperTrap.hpp"

SuperTrap::SuperTrap():ClapTrap("NoName"),FragTrap(),NinjaTrap()
{
	Hit_point = 100;
	Max_hit_points = 10;
	Energy_points = 120;
	Max_energy_points = 120;
	Level = 1;
	Name = "NoName";
	Melee_attack_damage = 60;
	Ranged_attack_damage = 30;
	Armor_damage_reduction = 5;
}

SuperTrap::SuperTrap(const char *name):ClapTrap(),FragTrap(),NinjaTrap()
{
	Hit_point = 100;
	Max_hit_points = 10;
	Energy_points = 120;
	Max_energy_points = 120;
	Level = 1;
	Name = name;
	Melee_attack_damage = 60;
	Ranged_attack_damage = 30;
	Armor_damage_reduction = 5;
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
