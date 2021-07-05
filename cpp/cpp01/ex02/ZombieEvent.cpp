#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent() :type("non type"){};

void	ZombieEvent::setZombieType(std::string input)
{
	this->type = input;
}

Zombie* ZombieEvent::newZombie(std::string input)
{
	Zombie *ret;
	ret = new Zombie(type, input);
	return (ret);
}

Zombie*	ZombieEvent::randomChump()
{
	srand(time(NULL));
	std::string str("");
	const char *temp = "qwertyuiopasdfghjklzxcvbnm";
	for (int i = 0;i<6;i++)
		str.push_back(temp[rand()%26]);
	Zombie *ret = new Zombie(this->type, str);
	ret->announce();
	return (ret);
}

ZombieEvent::~ZombieEvent()
{
	std::cout<<"Zombie Event class is disappeared!!!"<<std::endl;
}
