#include <iostream>

class Pony{
    private:
        std::string color;
        std::string name;
        std::string price;
    public:
        void    define_pony(std::string color, std::string name, std::string price);
        void    print_information();
        ~Pony();
};
void   ponyOnTheHeap(void);
void    ponyOnTheStack(void);
