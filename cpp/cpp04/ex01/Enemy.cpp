#include "Enemy.hpp"

Enemy::Enemy()
{}

Enemy::Enemy(int hp, std::string const & type): hp(hp), type(type), flag(0)
{}

Enemy::~Enemy()
{
	if(this->flag == 0)
	{
		std::cout<<"huhuhuhuh deeaaddd_aaaaaalvie"<<std::endl;
		this->flag = 1;
	}
}

Enemy::Enemy(const Enemy &src)
{
	*this = src;
}

Enemy &Enemy::operator=(const Enemy &src)
{
	this->hp = src.getHp();
	this->type = src.getType();
	return *this;
}

const std::string Enemy::getType() const
{
	return this->type;
}

int Enemy::getHp() const
{
	return this->hp;
}

void Enemy::takeDamage(int damage)
{
	if (damage < 0 || this->hp == 0)
		return ;
	else if (this->hp - damage < 0)
		damage = this->hp;
	this->hp -= damage;
	if(this->hp == 0 && this->flag == 0)
	{
		std::cout<<"huhuhuhuh deeaaddd_aaaaaalvie"<<std::endl;
		this->flag = 1;
	}
}

void Enemy::setFlag(int num)
{
	this->flag = num;
}

int Enemy::getFlag() const
{
	return this->flag;
}
