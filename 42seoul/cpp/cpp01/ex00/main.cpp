#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main(void)
{
    Zombie *ret = newZombie("test one Zombie");
    ret->announce();
    delete ret;
    randomChump("test two Zombie");
    return (0);
}
