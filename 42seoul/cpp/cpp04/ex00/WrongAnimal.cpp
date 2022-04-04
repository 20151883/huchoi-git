#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(std::string input)
{
    std::cout<<"the WrongAnimal's constructor"<<std::endl;
    this->type = input;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
    std::cout<<"the WrongAnimal's constructor"<<std::endl;
    this->type = src.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"the WrongAnimal's desstructor"<<std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    this->type = src.type;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout<<"WrongAnimallllllllllllllllll"<<std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}