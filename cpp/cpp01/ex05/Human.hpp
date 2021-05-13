#include <iostream>
#include "Brain.hpp"
//"with the same life time" 이 말이 뭔 뜻...?
class Human{
    private:
        const Brain brain;
    public:
        Human(const char *name) :brain(name)
		{ };
       	std::string identify() const;
        const Brain &getBrain() const;
        ~Human()
        {
            std::cout<<"human dead"<<std::endl;
        }
};
