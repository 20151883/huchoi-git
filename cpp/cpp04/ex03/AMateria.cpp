#include "AMateria.hpp"

AMateria::AMateria(std::string const & type):_xp(0), type(type)
{

}
AMateria::~AMateria() 
{

}
std::string const & AMateria::getType() const
{
    return this->type;
}

AMateria::AMateria(const AMateria &src)
{
    *this = src;
}

const AMateria &AMateria::operator=(const AMateria &src)
{
    this->_xp = src.getXP();
    this->type = src.type;
    return (*this);
}

unsigned int AMateria::getXP() const
{
    return this->_xp;
}

 void AMateria::use(ICharacter& target)
{
    (void)target;
    this->_xp += 10;
}