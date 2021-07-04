#include "Brain.hpp"

class Human{
    private:
        const Brain brain;
    public:
        Human(const char *name = "non name") :brain(name){};
       	std::string identify() const;
        const Brain &getBrain() const;
        ~Human();
};
