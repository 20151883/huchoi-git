#include "FragTrap.hpp"

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at range, causing <"<<Ranged_attack_damage<<"> points of damage!"<<std::endl;
}


void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout<<"FR4G-TP <"<<Name<<"> attacks <"<<target<<"> at melee, causing <"<<Ranged_attack_damage<<"> points of damage!"<<std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (amount >= Armor_damage_reduction)
		amount -= Armor_damage_reduction;
	else
		amount = 0;
	if (Hit_point <= amount)
		Hit_point = amount;
	Hit_point -= amount;
	std::cout<<"FR4G-TP <"<<Name<<"> attacked by someone,and caused <"<<amount<<"> points of damage!"<<std::endl;
	std::cout<<"and your hit point is "<<Hit_point<<std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (amount + Hit_point > Max_hit_points)
		amount = Max_hit_points - Hit_point;
	Hit_point += amount;
	std::cout<<"FR4G-TP <"<<Name<<"> repaired by angel,and repaired <"<<amount<<"> points of hp!"<<std::endl;
	std::cout<<"and your hit point is "<<Hit_point<<std::endl;
}
