#include "Enemy.hpp"

Enemy::Enemy()
{}
Enemy::Enemy(int hp, std::string const & type): hp(hp), type(type), flag(0)
{}
Enemy::~Enemy()
{}
Enemy::Enemy(Enemy &src)
{
	this->hp = src.hp;
	this->type = src.type;
}
Enemy &Enemy::operator=(Enemy &src)
{
	this->hp = src.hp;
	this->type = src.type;
	return *this;
}
std::string Enemy::getType() const
{
	return this->type;
}
int Enemy::getHp() const
{
	return this->hp;
}
void Enemy::setFlag(int num)
{
	this->flag = num;
}
int Enemy::getFlag()
{
	return this->flag;
}
