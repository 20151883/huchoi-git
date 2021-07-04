#include "ZombieEvent.hpp"
//clang++ main.cpp Zombie.cpp ZombieEvent.cpp
int main(void)
{
    ZombieEvent test;
    test.setZombieType("deer");
    Zombie *zombie_one = test.newZombie("huchoi");
    zombie_one->announce();
    delete zombie_one;
    Zombie *zombie_two;
    test.setZombieType("apple");
    zombie_two = test.newZombie("devil");
    zombie_two->announce();
    delete zombie_two;
    Zombie *zombie_three;
    test.setZombieType("third zombie type");
    zombie_three = test.randomChump();
    delete zombie_three;
    return (0);
}
