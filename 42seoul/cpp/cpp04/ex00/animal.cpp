#include "animal.hpp"

Animal::Animal(std::string input)
{
    std::cout<<"the animal's constructor"<<std::endl;
    this->type = input;
}

Animal::Animal(const Animal &src)
{
    std::cout<<"the animal's constructor"<<std::endl;
    this->type = src.type;
}

Animal::~Animal()
{
    std::cout<<"the animal's destructor"<<std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
    this->type = src.type;
    return *this;
}

void Animal::makeSound() const
{
    std::cout<<"animallllllllllllllllll"<<std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}