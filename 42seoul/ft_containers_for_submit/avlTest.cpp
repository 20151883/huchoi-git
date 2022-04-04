#include "map.hpp"
#include "etc.hpp"
int main(void){
	ft::map<int, int> m1;


	m1.insert(ft::make_pair(5, 5));
	//m1.preOrder(m1._RNode, 1);
	std::cout << std::endl;
	m1.insert(ft::make_pair(4, 4));
	//m1.preOrder(m1._RNode, 1);
	std::cout << std::endl;
	m1.insert(ft::make_pair(3, 3));
	//m1.preOrder(m1._RNode, 1);
	std::cout << std::endl;

	m1.insert(ft::make_pair(2, 2));
	//m1.preOrder(m1._RNode, 1);
	std::cout << std::endl;
	m1.insert(ft::make_pair(6, 6));
	//m1.preOrder(m1._RNode, 1);
	std::cout << std::endl;
	m1.insert(ft::make_pair(1, 1));
	m1.preOrder(m1._RNode, 1);
	std::cout << std::endl;

	/*
	ft::map<int, int>::iterator iter = m1.begin();
	for (;iter != m1.end(); iter++){
		std::cout << iter->first << std::endl;
	}
	*/
	return 0;
}
