#include <iostream>
#include "Zombie.hpp"
//객체핸들러를 하나 만들라는것.
class ZombieEvent
{
    private:
		std::string type;
    public:
		Zombie *z_ptr;//퍼블릭으로 빼는 방법밖에는 없는거 같음.
		ZombieEvent() :type(""), z_ptr(NULL)
		{};
        void	setZombieType(std::string input);//캡슐화를 진행해야 할거같은데...?
        Zombie*	newZombie(std::string name);
        void	randomChump();
		~ZombieEvent()
		{
			if (z_ptr != NULL)
				delete z_ptr;
			std::cout<<"in desconstructor.... zombie is disappeared!!"<<std::endl;
		}
};