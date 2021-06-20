#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :Enemy(80,"RadScorpion")
{
	std::cout<<"* click click click *"<<std::endl;
	this->dead = "* SPROTCH *";
}
RadScorpion::~RadScorpion()
{}
RadScorpion::RadScorpion(RadScorpion &src) :Enemy(src.getHp(), src.getType())
{
	this->hp = src.hp;
	this->type = src.type;
	this->dead = src.dead;
	this->flag = src.flag;
}
RadScorpion &RadScorpion::operator=(RadScorpion &src)
{
	this->hp = src.hp;
	this->type = src.type;
	this->dead = src.dead;
	this->flag = src.flag;
	return *this;
}
void RadScorpion::takeDamage(int num)
{
	if (num < 0)
		return;
	int dmg = num;
	this->hp -= dmg;
	if (this->hp <= 0)
	{
		if (this->flag == 0)
			std::cout<<this->dead<<std::endl;
		this->flag = 1;
		this->hp = 0;
	}
}
