#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *arr = new Zombie[N];
	for (int i = 0; i < N ; i++)
	{
		arr[i].setZomnieName(name);
	}
	return (&arr[0]);
}
