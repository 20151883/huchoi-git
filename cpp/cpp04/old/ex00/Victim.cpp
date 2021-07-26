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

void	Victim::getPolymorphed() const//const함수라서 status값 변경할수가 없겠다.
{
	std::cout << this->name <<" has been turned into a cute little sheep!" << std::endl;
}

const std::string &Victim::getName (void) const
{
	return this->name;
}

void Victim::setName (const std::string &test)
{
	this->name = test;
}

const Victim &Victim::operator=(const Victim &src)
{
	this->name = src.getName();
	return *this;
}

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
