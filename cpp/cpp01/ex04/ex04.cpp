#include <iostream>


int main(void)
{
    std::string str("HI THIS IS BRAIN");
    std::string *pointer = &str;
    std::string &ref = str;

    std::cout<<*pointer<<"  address is "<<pointer<<std::endl;
    std::cout<<ref<<"  address is "<<&ref<<std::endl;
    return (0);
}