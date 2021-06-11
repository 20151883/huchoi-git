#include "span.hpp"
int main()
{
	try{
		Span sp = Span(6);
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::runtime_error &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	catch(...)//std::exception의 생성자는 문자열을 인자로 받을수없다. std::rubtime_error("this is error")처럼 다른 예외클래스는 가능하다.
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}
