#include "Victim.hpp"

Victim::Victim()
{}

Victim::Victim(const char *n) :name(n)
{
	std::cout<<"Some random victim called "<<name<<" just appeared!"<<std::endl;
}

Victim::Victim(const Victim &src)
{
	name = src.getName();
}

void	Victim::getPolymorphed() const
{
	std::cout << this->name <<" has been turned into a cute little sheep!" << std::endl;
}

std::string Victim::getName (void) const
{
	return this->name;
}

void Victim::setName (std::string &test)
{
	this->name = test;
}

Victim &Victim::operator=(Victim &src)
{
	this->name = src.getName();
	return *this;
}

//virtual Peon	&operator=(Peon &src) = 0;//순수가상함수
Victim::~Victim()
{
	std::cout<<"Victim "<< name <<" just died for no apparent reason!"<<std::endl;
}

std::ostream& operator<<(std::ostream &ost, Victim &src)
{
	ost<<"I'm "<<src.getName()<<" and I like otters!\n";
	ost.flush();
	return ost;
}
