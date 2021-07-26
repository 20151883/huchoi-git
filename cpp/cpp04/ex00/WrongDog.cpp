#include "WrongDog.hpp"

WrongDog::WrongDog()
{
    this->type = "WrongDog";
    std::cout<<"WrongDog constructer"<<std::endl;
}
WrongDog::WrongDog(const WrongDog &src)
{
    this->type = src.type;
    std::cout<<"WrongDog constructer"<<std::endl;
}

WrongDog::~WrongDog()
{
    std::cout<<"WrongDog destructer"<<std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &src)
{
    this->type = src.type;
    return *this;
}

void WrongDog::makeSound() const
{
    std::cout<<"WrongDoggggggggggggggggggga"<<std::endl;
}