#include "stack.hpp"
#include <stack>
#include <deque>

int main(void)
{
	try{
		ft::stack<int, std::deque<int> > test;
		//ft::stack<int> test
		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);
		test.push(5);
		test.push(6);
		std::cout << test.top() <<std::endl;
		test.pop();
		std::cout << test.top() <<std::endl;
		test.pop();
		std::cout << test.top() <<std::endl;
		test.pop();
		std::cout << test.top() <<std::endl;
		test.pop();
		std::cout << test.top() <<std::endl;
		test.pop();
		std::cout << test.top() <<std::endl;
		test.pop();
	
		ft::stack<int> test2;
		//ft::stack<int> test
		test2.push(1);
		test2.push(2);
		test2.push(3);
		test2.push(4);
		test2.push(5);
		test2.push(6);
		//std::cout << (test == test2) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<<"??"<<std::endl;
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}