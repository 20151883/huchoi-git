#include <iterator>
#include <vector>
#include <list>
#include <iostream>
#include <set>
#include "etc.hpp"

int main(void)
{
	//https://en.cppreference.com/w/cpp/iterator/reverse_iterator/operator- (여기 설명 참조할것.)
	std::vector<int> vec(10, 42);
	std::list<int> lst(20, 84);
	std::list<int> lst2(40, 168);
	std::set<int> st;

	ft::reverse_iterator<std::vector<int>::iterator> r_vector_iter(vec.end());
	ft::reverse_iterator<std::list<int>::iterator> r_lst_iter(lst.begin());
	ft::reverse_iterator<std::set<int>::iterator> r_set_iter(st.begin());
	//std::reverse_iterator<std::list<int>::iterator> new_iter(r_lst_iter);
	//std::reverse_iterator<std::list<int>::iterator> new_iter(r_vector_iter);//이터레이터 호환성문제.
	ft::reverse_iterator<std::list<int>::iterator> new_iter(r_lst_iter);

	std::cout << (new_iter != r_lst_iter) << std::endl;
	//std::cout << (new_iter - r_lst_iter) << std::endl;
	r_vector_iter++;
	//std::cout << ft::operator-(r_vector_iter, new_iter) << std::endl;
	//ft::operator==(new_iter, r_lst_iter);
	return (0);
}