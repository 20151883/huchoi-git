#include <iostream>
struct Data{
    int num;
    char c;
    float f;
    double d;
    std::string str;
};

std::ostream& operator<<(std::ostream &ost, Data src);

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

