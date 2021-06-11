#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int N) :num_of_zombies(N), type("NOTYPE")
{
    srand((unsigned int)time(NULL));
    p_zombies = new Zombie[N];
    int idx = 0;
    std::string name;
    std::string type;
    while (idx < N)
    {
        name = this->random();
        type = this->random();
        type.append("type");
        const Zombie &ref = Zombie(type, name);
        this->p_zombies[idx] = ref;
        idx++;
    }
}
ZombieHorde::~ZombieHorde()
{
    delete []p_zombies;
}
void    ZombieHorde::announce()//all of zombies announec....
{
    int idx = 0;
    while (idx < num_of_zombies)
        p_zombies[idx++].announce();
}

std::string	ZombieHorde::random()
{
	std::string str("");
	const char *temp = "qwertyuiopasdfghjklzxcvbnm";
	for (int i = 0;i<6;i++)
    {
		str.push_back(temp[(rand())%26]);
    }
	return str;
}
