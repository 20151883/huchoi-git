#include <iostream>
#include <ctime>
#include "Zombie.hpp"

class ZombieEvent
{
	private:
		std::string type;
	public:
		ZombieEvent();
		void	setZombieType(std::string input);
		Zombie*	newZombie(std::string name);
		Zombie*	randomChump();
		~ZombieEvent();
};
