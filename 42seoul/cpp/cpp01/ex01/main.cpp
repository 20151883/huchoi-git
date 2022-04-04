#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

void test()
{
	Zombie*test = zombieHorde(10, "this is test");
	for (int i = 0;i < 10; i++)
	{
		(test + i)->announce();
	}
	delete []test;

}

int main(void)
{
	/*Zombie*test = zombieHorde(10, "this is test");
	for (int i = 0;i < 10; i++)
	{
		(test + i)->announce();
	}
	delete*/
	test();
	while (1)
	{}
	return 0;
}
