#include "Cure.hpp"

Cure::Cure() :AMateria("cure")
{}

Cure::Cure(const Cure &src)  :AMateria("cure")
{
    this->_xp = src.getXP();
}

Cure &Cure::operator=(Cure &src)
{
    this->_xp = src.getXP();
    return *this;
}

Cure::~Cure()
{}

void Cure::use(ICharacter& target)//오버로딩
{
    AMateria::use(target);
    std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}

AMateria* Cure::clone() const
{
    AMateria *ret = new Cure(*this);
    return ret;
}