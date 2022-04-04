#include <iostream>


class Parent
{
public:
    Parent() { std::cout << "Parent " << std::endl; }
    ~Parent() { std::cout << "~Parent " << std::endl; }

    void say()
    {
        std::cout << "parent say" << std::endl;
    }
};

class Child : public Parent
{
public:
    Child() { std::cout << "Child " << std::endl; }
    virtual ~Child() { std::cout << "~Child " << std::endl; }

    void say()
    {
        std::cout << "Child say" << std::endl;
    }
};


int main()
{
    Parent* ptr_p_instance = new Child();
    Child* ptr_c_instance;


    ptr_p_instance->say();

    // dynamic_cast를 사용한 down casting 
    ptr_c_instance = dynamic_cast<Child*>(ptr_p_instance);

    if (ptr_p_instance == nullptr) {
        std::cout << "error compile" << std::endl;
    }
    ptr_c_instance->say();


    return 0;
}