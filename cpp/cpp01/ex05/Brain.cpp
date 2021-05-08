#include <iostream>

class Brain{
    private:
        std::string brain_name;
    public:
        Brain(char *name) :brain_name(name)
        {}
        std::string identify()
        {
            std::string ret = this;
        }
}

int main(void)
{
    Human bob;
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
    return (0);
}