#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) :num_of_zombies(N), type("NOTYPE")
{
	srand((unsigned int)time(NULL));
	Zombie **arr = new Zombie*[N];
	int idx = 0;
	std::string name;
	std::string type;
	while (idx < N)
	{
		name = this->ft_random();
		type = this->ft_random();
		type.append(" type");
		arr[idx] = new Zombie(type, name);
		idx++;
	}
	this->p_zombies = arr;
}
ZombieHorde::~ZombieHorde()
{
	for (int i = 0;i < this->num_of_zombies;i++)
		delete (this->p_zombies[i]);
	delete (this->p_zombies);
}
void	ZombieHorde::announce()
{
	int idx = 0;
	while (idx < num_of_zombies)
		p_zombies[idx++]->announce();
}

std::string	ZombieHorde::ft_random()
{
	std::string str("");
	const char *temp = "qwertyuiopasdfghjklzxcvbnm";
	for (int i = 0;i<6;i++)
	{
		str.push_back(temp[(rand())%26]);
	}
	return str;
}
