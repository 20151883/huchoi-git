#include <iostream>
//객체핸들러를 하나 만들라는것.
class ZombieEvent
{
    private:
		std::string type;
    public:
        void setZombieType();
        Zombie* newZombie(std::string name);
        void randomChump();
}

void	ZombieEvent::setZombieType(std::string input)
{
	type(input);//복사생성자를 유도하기위해서
}

Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *ret = new Zombie(type, name);//delete는 언제 진행?
	return (ret);
}

void	ZombieEvent::randomChump();
{
    
}