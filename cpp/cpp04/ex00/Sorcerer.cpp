#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{}

Sorcerer::Sorcerer(const char *n, const char *t) :name(n), title(t)
{
	std::cout<<name<<", "<<title<<", is born!"<<std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &src)
{
	this->name = src.name;
	this->title = src.title;
}

void Sorcerer::announce() const
{
	 std::cout<<"I am"<<name<<", "<<title<<","<<", and I like ponies!"<<std::endl;
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::string Sorcerer::getName()
{
	return name;
}

std::string Sorcerer::getTitle()
{
	return title;
}

Sorcerer &Sorcerer::operator=(Sorcerer &src)
{
	this->name = src.getName();
	this->title = src.getTitle();
	return *this;
}

Sorcerer::~Sorcerer()
{
	 std::cout<<name<<", "<<title<<", is dead. Consequences will never be the same!"<<std::endl;
}

std::ostream& operator<<(std::ostream &ost, Sorcerer &src)
{
	printf("I am %s, %s, and I like ponies!\n", src.getName().c_str(), src.getTitle().c_str());
	fflush(stdout);
	return ost;
}
