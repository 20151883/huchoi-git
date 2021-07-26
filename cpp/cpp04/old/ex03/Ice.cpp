#include "Ice.hpp"

Ice::Ice() :AMateria("ice")
{}

Ice::Ice(const Ice &src)  :AMateria("ice")
{
    this->_xp = src.getXP();
}

Ice &Ice::operator=(Ice &src)
{
    this->_xp = src.getXP();
    return *this;
}

Ice::~Ice()
{}

void Ice::use(ICharacter& target)//오버로딩에 대해 얘기하고 싶은듯
{
    AMateria::use(target);
    std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

AMateria* Ice::clone() const
{
    AMateria *ret = new Ice(*this);
    return ret;
}
