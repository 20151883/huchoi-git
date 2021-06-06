#include "form.hpp"
//#include "Bureaucrat.hpp"
​
int main()
{
    Form* set = new Form("42seoul", 50, 100);
    std::cout << *set;
​
    std::cout << std::endl;
    Form* high;
    try
    {
       high = new Form("High", 0, 100);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
​
    std::cout << std::endl;
    try
    {
       high = new Form("High", 50, 0);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
​
    std::cout << std::endl;
    Form* low;
    try
    {
       low = new Form("Low", 50, 200);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
​
    std::cout << std::endl;
    try
    {
       low = new Form("Low", 200, 50);
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
​
    std::cout << std::endl;
    Bureaucrat* mike = new Bureaucrat("mike", 5);
    std::cout << *mike;
    mike->signForm(*set);
​
    std::cout << std::endl;
    std::cout << *set;
​
    std::cout << std::endl;
    mike->signForm(*set);
​
    std::cout << std::endl;
    Form* set2 = new Form("42paris", 50, 100);
    Bureaucrat* chuck = new Bureaucrat("chuck", 75);
    std::cout << *chuck;
    chuck->signForm(*set2);
    
    delete set;
    delete mike;
    delete set2;
    delete chuck;
}