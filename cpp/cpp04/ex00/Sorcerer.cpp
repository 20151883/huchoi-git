#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{
	std::cout<<"private void constructor is called"<<std::endl;
}

Sorcerer::Sorcerer(const char *n, const char *t) :name(n), title(t)
{
	std::cout<<name<<", "<<title<<", is born!"<<std::endl;
}

Sorcerer &Sorcerer::operator=(const Sorcerer &src)//여기서 매개변수 자료형을 const로 바꾸면서 파생된 문제에 대해 생각해보긴
{
	this->name = src.getName();
	this->title = src.getTitle();
	return *this;
}

Sorcerer::Sorcerer(const Sorcerer &src)
{
	*this = src;
}

void Sorcerer::announce()
{
	 std::cout<<"I am"<<name<<", "<<title<<","<<", and I like ponies!"<<std::endl;
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

const std::string &Sorcerer::getName() const
{
	return name;
}

const std::string &Sorcerer::getTitle() const
{
	return title;
}

Sorcerer::~Sorcerer()
{
	 std::cout<<name<<", "<<title<<", is dead. Consequences will never be the same!"<<std::endl;
}

std::ostream& operator<<(std::ostream &ost, Sorcerer &src)
{
	ost<<"I am "<<src.getName()<<", "<<src.getTitle()<<", and I like ponies!\n";
	ost.flush();
	return ost;
}
