#include "cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout<<"Cat constructer"<<std::endl;
}
Cat::Cat(const Cat &src)
{
    this->type = src.type;
    std::cout<<"Cat constructer"<<std::endl;
}

Cat::~Cat()
{
    std::cout<<"Cat destructer"<<std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    this->type = src.type;
    return *this;
}

void Cat::makeSound() const
{
    std::cout<<"Catttttttttttttttttttttttt"<<std::endl;
}