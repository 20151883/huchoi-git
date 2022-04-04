#include "dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    ptr = new Brain();
    std::cout<<"Dog constructer"<<std::endl;
}
Dog::Dog(const Dog &src)
{
    this->type = src.type;
    this->ptr = new Brain(*src.ptr);
    std::cout<<"Dog constructer"<<std::endl;
}

Dog::~Dog()
{
    delete ptr;
    std::cout<<"Dog destructer"<<std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
    this->type = src.type;
    this->ptr = new Brain(*src.ptr);
    return *this;
}

void Dog::makeSound() const
{
    std::cout<<"Doggggggggggggggggggga"<<std::endl;
}