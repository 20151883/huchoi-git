#include <iostream>

class Sorcerer{
    private:
        std::string name;
        std::string title;
    public:
        Sorcerer(const char *n, const char *t) :name(n), title(t)
        {
            std::cout<<name<<", "<<title<<", is born!"<<std::endl;
        }
        Sorcerer(Sorcerer src)
        {
            (*this) = src;
        }
        void announce()
        {
             std::cout<<name<<", "<<title<<",";
        }
        ~Sorcerer()
        {
             std::cout<<name<<", "<<title<<", is dead. Consequences will never be the same!"<<std::endl;
        }
};  
