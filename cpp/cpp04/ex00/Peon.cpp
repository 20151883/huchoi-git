#include "Peon.hpp"

Peon::Peon()
{}

Peon::Peon(const char *n) :Victim()
{
	this->name = n;
	std::cout<<"Zog zog."<<std::endl;
}

Peon::Peon(const Peon &src) :Victim()
{
	this->name = src.getName();
	std::cout<<"Zog zog."<<std::endl;
}

void	 Peon::getPolymorphed() const
{
	std::cout << getName() <<" has been turned into a pink pony!" << std::endl;
}

Peon	&Peon::operator=(Peon &src)
{
	setName(src.getName());
	return *this;
}

Peon::~Peon()
{
	std::cout<<"Bleuark..."<<std::endl;
}
