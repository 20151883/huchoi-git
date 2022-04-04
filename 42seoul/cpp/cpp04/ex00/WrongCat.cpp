#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout<<"WrongCat constructer"<<std::endl;
}
WrongCat::WrongCat(const WrongCat &src)
{
    this->type = src.type;
    std::cout<<"WrongCat constructer"<<std::endl;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat destructer"<<std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src)
{
    this->type = src.type;
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout<<"WrongCatttttttttttttttttttttttt"<<std::endl;
}