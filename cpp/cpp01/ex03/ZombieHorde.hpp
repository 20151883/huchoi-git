#include <iostream>
#include "Zombie.hpp"
class ZombieHorde{
	private:
		Zombie **p_zombies;
		int		num_of_zombies;
		std::string type;
	public:
		ZombieHorde(int N);
		~ZombieHorde();
		void	announce();
		std::string	random();	
};
