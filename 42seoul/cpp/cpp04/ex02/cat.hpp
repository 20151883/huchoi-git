#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain *ptr;
    public:
        Cat();
        Cat(const Cat &src);
        ~Cat();
        Cat &operator=(const Cat &src);
        void makeSound() const ;
};

#endif