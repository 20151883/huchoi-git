#include "Zombie.hpp"

Zombie::Zombie(std::string input_type, std::string input_name)
{
    this->type = input_type;
    this->name = input_name;
}
void    Zombie::announce(void)
{
    std::cout<<"<"<<this->name<<"("<<this->type<<")>"<<"Braiiiiiiinnnssss..."<<std::endl;
}
Zombie::~Zombie(void)
{
    std::cout<<"***********<"<<this->name<<"("<<this->type<<")>"<<"disappeared!!!***************"<<std::endl;
}
