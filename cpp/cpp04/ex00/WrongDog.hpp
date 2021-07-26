#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
    public:
        WrongDog();
        WrongDog(const WrongDog &src);
        ~WrongDog();
        WrongDog &operator=(const WrongDog &src);
        void makeSound() const;
};

#endif