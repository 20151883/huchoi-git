#include <iostream>
//객체 핸들러를 하나 만들라는것.
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