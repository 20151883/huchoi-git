#include "dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout<<"Dog constructer"<<std::endl;
}

Dog::Dog(const Dog &src)
{
    this->type = src.type;
    std::cout<<"Dog constructer"<<std::endl;
}

Dog::~Dog()
{
    std::cout<<"Dog destructer"<<std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    this->type = src.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout<<"Doggggggggggggggggggga"<<std::endl;
}
