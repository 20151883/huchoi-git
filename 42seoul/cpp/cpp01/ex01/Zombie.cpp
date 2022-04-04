#include "Zombie.hpp"

Zombie::Zombie(std::string input_name)
{
    this->name = input_name;
}
void    Zombie::announce(void)
{
    std::cout<<"<"<<this->name<<">"<<" BraiiiiiiinnnzzzZ....."<<std::endl;
}

void    Zombie::setZomnieName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout<<"***********<"<<this->name<<" disappeared!!!***************"<<std::endl;
}
