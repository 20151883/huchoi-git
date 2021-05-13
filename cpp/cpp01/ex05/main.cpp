#include "Human.hpp"

int main(void)
{
    Human bob("bob");
    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
    //위 둘의 결과가 동일해야함.
    //객체와 객체가 엮이는 상황에서 소멸자에 대한 얘기
    //1. 클래스 상속 : 여기서 소멸자는 virtual 키워드를 붙여야지 연쇄적으로 소멸자가 호출됨
    //2. 객체안에 멤버변수로 객체를 선언 : 여기서는 딱히 처리를 하지 않아도 자동적으로 소멸자가 연쇄적으로 호출됨.
    return (0);
}