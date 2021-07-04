#include "Pony.hpp"

void    Pony::define_pony(std::string my_color, std::string my_name, std::string my_price)
{
    color = my_color;
    name = my_name;
    price = my_price;
}

void    Pony::print_information()
{
    std::cout<<name<<" "<<color<<" "<<price<<std::endl;
}

Pony::~Pony()
{
    std::cout<<this->name<<" pony is disappeared...."<<std::endl;
}

void   ponyOnTheHeap(void)
{
    Pony *ptr = new Pony;
    ptr->define_pony("black_HEAP", "django", "$1000");
    ptr->print_information();
    delete ptr;
}

void    ponyOnTheStack(void)
{
	Pony stack;
    stack.define_pony("white_STACK", "디카프리오", "$500");
    stack.print_information();
}

