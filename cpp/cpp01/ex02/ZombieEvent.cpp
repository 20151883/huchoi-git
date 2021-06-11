#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(std::string input)
{
	type = input;
}

Zombie* ZombieEvent::newZombie(std::string input)
{
	if (z_ptr != NULL)
	{
		delete z_ptr;
	}
	if (type.size() == 0)
		type = "NONTYPE";
	z_ptr = new Zombie(type, input);//delete는 언제 진행? 소멸자에서 진행.
	return (z_ptr);
}

void	ZombieEvent::randomChump()
{
	srand(time(NULL));
	std::string str("");
	const char *temp = "qwertyuiopasdfghjklzxcvbnm";
	for (int i = 0;i<6;i++)
		str.push_back(temp[rand()%26]);

	if (this->z_ptr != NULL)
		delete z_ptr;
	this->z_ptr = new Zombie(this->type, str);
	this->z_ptr->announce();
}

ZombieEvent::~ZombieEvent()
{
	if (z_ptr != NULL)
	{
		delete z_ptr;
	}
}
