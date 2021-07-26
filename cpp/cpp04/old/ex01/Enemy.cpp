#include "Enemy.hpp"

Enemy::Enemy()
{}

Enemy::Enemy(int hp, std::string const & type): hp(hp), type(type)
{}

Enemy::~Enemy()
{}	

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
	(void)damage;
}

