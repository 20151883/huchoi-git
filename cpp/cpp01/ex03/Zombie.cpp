#include <iostream>

class Zombie
{
    private:
        std::string type;
        std::string name;
    public:
        Zombie(std::string input_type, std::string input_name) :type(input_type) :name(input_name)
        { };
        void announce(void);
}

void    announce(void)
{
    std::cout<<"<"<<name<<"("<<type<<")>"<<"Braiiiiiiinnnssss..."<<std::endl;
}