#include <iostream>

class Pony{//클래스 멤버로 뭘 넣어야할지 잘 모르겠음.
    private:
        std::string color;
        std::string name;
        std::string price;
    public:
        void    define_pony(std::string color, std::string name, std::string price);
        void    print_information();
        ~Pony()
        {
            std::cout<<"the pony is disappeared...."<<std::endl;
        }
};

void    Pony::define_pony(std::string my_color, std::string my_name, std::string my_price)
{
    color = my_color;
    name = my_name;
    price = my_price;
}

void    Pony::print_information()
{
    std::cout<<name<<color<<price<<std::endl;
}

void   ponyOnTheHeap(void)
{
    Pony *ptr = new Pony;
    ptr->define_pony("black", "django", "$1000");
    ptr->print_information();
    delete ptr;
}

void    ponyOnTheStack(void)
{
	Pony stack;
    stack.define_pony("white", "디카프리오", "$500");
    stack.print_information();
}

int main(void)
{
    ponyOnTheHeap();
    ponyOnTheStack();
    return (0);
}