#include <iostream>

class Brain{
    private:
        std::string brain_name;
    public:
        Brain(const char *name) :brain_name(name){}
        std::string identify() const;
        ~Brain();
};
