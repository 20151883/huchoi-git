#include "Zombie.hpp"
//객체 핸들러를 하나 만들라는것.

void    Zombie::announce(void)
{
    std::cout<<"<"<<name<<"("<<type<<")>"<<"Braiiiiiiinnnssss..."<<std::endl;
}