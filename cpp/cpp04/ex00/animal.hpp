#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal(std::string input = "non type");
        Animal(const Animal &src);
        virtual ~Animal();
        Animal &operator=(const Animal &src);
        virtual void makeSound() const;
        std::string getType() const;
};



#endif