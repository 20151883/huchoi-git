#include "cat.hpp"
#include "dog.hpp"

int main()
{
    const Animal* j = new Dog(); 
    const Animal* i = new Cat();
    delete j;//should not create a leak
    delete i;

    //Animal test;
    return (0);
}