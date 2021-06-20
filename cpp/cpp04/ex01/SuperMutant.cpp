#include "SuperMutant.hpp"

SuperMutant::SuperMutant() :Enemy(170,"Super Mutant")
{
	std::cout<<"Gaaah. Me want smash heads!"<<std::endl;
	this->dead = "Aaargh...";
}

SuperMutant::~SuperMutant()
{}

SuperMutant::SuperMutant(SuperMutant &src):Enemy(src.getHp(), src.getType())
{
	this->hp = src.hp;
	this->type = src.type;
	this->dead = src.dead;
	this->flag = src.flag;
}

SuperMutant &SuperMutant::operator=(SuperMutant &src)
{
	this->hp = src.hp;
	this->type = src.type;
	this->dead = src.dead;
	this->flag = src.flag;
	return *this;
}

void SuperMutant::takeDamage(int num)
{
	if (num < 0)
		return;
	int dmg = num > 3 ? num - 3 : 0;
	this->hp -= dmg;
	if (this->hp <= 0)
	{
		if (this->flag == 0)
			std::cout<<this->dead<<std::endl;
		this->flag = 1;
		this->hp = 0;
	}
}
