#ifndef DOG_HPP
#define DOG_HPP

#include "animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &src);
        ~Dog();
        Dog &operator=(const Dog &src);
        void makeSound() const;
};


#endif