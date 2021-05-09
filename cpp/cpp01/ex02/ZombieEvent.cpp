#include "ZombieEvent.hpp"

void	ZombieEvent::setZombieType(std::string input)
{
	type = input;//복사생성자를 유도하기위해서
}

Zombie* ZombieEvent::newZombie(std::string input)
{
	if (z_ptr != NULL)
	{
		std::cout<<"in newZombie function... Zombie is disappeared!!!"<<std::endl;
		delete z_ptr;
	}
	if (type.size() == 0)
		type = "NONTYPE";
	z_ptr = new Zombie(type, input);//delete는 언제 진행? 소멸자에서 진행.
	return (z_ptr);
}

void	ZombieEvent::randomChump()
{
	std::cout<<"test"<<std::endl;
    return ;
}