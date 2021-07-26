#include "cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    ptr = new Brain();
    std::cout<<"Cat constructer"<<std::endl;
}
Cat::Cat(const Cat &src)
{
    this->type = src.type;
    this->ptr = new Brain(*src.ptr);
    std::cout<<"Cat constructer"<<std::endl;
}

Cat::~Cat()
{
    delete ptr;
    std::cout<<"Cat destructer"<<std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
    this->type = src.type;
    this->ptr = new Brain(*src.ptr);
    return *this;
}

void Cat::makeSound() const
{
    std::cout<<"Catttttttttttttttttttttttt"<<std::endl;
}