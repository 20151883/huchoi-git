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

Peon	&Peon::operator=(Peon &src)//차라리 Victim에서 멤버변수를 protected 로 두었으면 더 편했을수도...
{
	std::string str = src.getName();
	this->setName(str);
	return *this;
}

Peon::~Peon()
{
	std::cout<<"Bleuark..."<<std::endl;
}
