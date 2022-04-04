#include "etc.hpp"
#include "../vector/vector.hpp"
#include <vector>
#include <list>
#include <set>

int main(void)
{

	std::vector<int> vec(3, 42);
	std::list<int> lst(20, 84);
	std::list<int> lst2(40, 168);
	std::set<int> st;

	ft::reverse_iterator<std::vector<int>::iterator> r_vector_iter(vec.end());//rbegin()에 대해서 잘못알고 있었음.
	for (; r_vector_iter != ft::reverse_iterator<std::vector<int>::iterator>(vec.begin()) ; r_vector_iter++)
	{
		std::cout << *r_vector_iter << std::endl;
		sleep(1);
	}
	ft::reverse_iterator<std::list<int>::iterator> r_lst_iter(lst.begin());
	ft::reverse_iterator<std::set<int>::iterator> r_set_iter(st.begin());

	//ft::reverse_iterator<std::list<int>::iterator> new_iter(r_lst_iter);
	//ft::reverse_iterator<std::list<int>::iterator> new_iter(r_vector_iter);//이터레이터 호환성문제.
	//ft::reverse_iterator<std::list<int>::iterator> new_iter(r_set_iter);
	
	ft::pair<int, double> _pair(3, 10.0);
	ft::pair<int, double> _pair2 =  ft::make_pair(3, 10.0);
	std::cout << _pair.first << " " << _pair.second <<std::endl;;
	std::cout << (_pair == _pair2) <<std::endl;
	

	return (0);
}