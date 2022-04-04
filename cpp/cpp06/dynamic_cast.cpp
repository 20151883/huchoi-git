#include <iostream>

class Parent{
    public:
        virtual ~Parent(){}
};

class Child_One :public Parent{

};

class Child_Two :public Parent{

};

int main(){
    Parent *Parentptr = new Child_One;
    Child_Two *childPtr = dynamic_cast<Child_Two>(Parentptr);

    return 0;
}