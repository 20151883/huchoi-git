#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain constructor"<<std::endl;
}

Brain::Brain(const Brain &src)
{
    std::cout<<"Brain constructor"<<std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
    std::cout<<"Brain destructor"<<std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
     for (int i = 0; i < 100; i++)
        ideas[i] = src.ideas[i];
    return *this;
}