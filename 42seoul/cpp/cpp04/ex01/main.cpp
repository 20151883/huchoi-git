#include "cat.hpp"
#include "dog.hpp"

int main()
{
    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    std::cout<<"***************"<<std::endl;

    Dog t1;
    Dog t2;

    std::cout<<"***************"<<std::endl;

    t1 = t2;

    std::cout<<"***************"<<std::endl;
    return (0);
}