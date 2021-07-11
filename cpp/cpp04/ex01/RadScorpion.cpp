#include "RadScorpion.hpp"

RadScorpion::RadScorpion() :Enemy(80,"RadScorpion")
{
	std::cout<<"* click click click *"<<std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout<<"* SPROTCH *"<<std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &src) :Enemy(src.getHp(), src.getType())
{
	std::cout<<"* click click click *"<<std::endl;
}

RadScorpion &RadScorpion::operator=(const RadScorpion &src)
{
	this->hp = src.getHp();
	this->type = src.getType();
	return *this;
}

void RadScorpion::takeDamage(int num)
{
	if (num < 0)
		return;
	int dmg = num;
	this->hp -= dmg;
	if (this->hp <= 0)
		this->hp = 0;
}
