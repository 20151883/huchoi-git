#include <iostream>
#include <ctime>
#include "Zombie.hpp"
class ZombieEvent
{
	private:
		std::string type;
		Zombie *z_ptr;
	public:
		ZombieEvent() :type(""), z_ptr(NULL){};
		void	setZombieType(std::string input);
		Zombie*	newZombie(std::string name);
		void	randomChump();
		~ZombieEvent();
};
