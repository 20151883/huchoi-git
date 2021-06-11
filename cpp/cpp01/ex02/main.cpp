#include "ZombieEvent.hpp"
//clang++ main.cpp Zombie.cpp ZombieEvent.cpp
int main(void)
{
    ZombieEvent test;
    test.setZombieType("deer");
    Zombie *ptr = test.newZombie("huchoi");
    ptr->announce();
    test.setZombieType("apple");
    ptr = test.newZombie("devil");
    ptr->announce();
    test.randomChump();
    return (0);
}
