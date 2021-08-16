#include <set>
#include <iostream>
#include <map>
#include "map.hpp"

template <class T>
void container_print(T container)
{
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
		std::cout << "key:  " << iter->first << " value :    " << iter->second << ";  ";
	std::cout << std::endl;
}

int main()
{
	try
	{
		ft::map<int, double> map;
		/*std::set<int> test;
		test.insert(10);
		test.insert(20);
		test.insert(30);
		for (std::set<int>::iterator i = test.begin(); i != test.end() ; i++)
		{
			std::cout << &*i << "      " << std::distance(i, test.begin()++) <<std::endl;
		}
		for (std::set<int>::reverse_iterator i = test.rbegin(); i != test.rend() ; i++)
		{
			std::cout << &*i << "      " << std::distance(i, test.rend()) <<std::endl;
		}
		std::cout << &*test.end() << std::endl;
		std::cout << &*test.end() << std::endl;
		std::cout << &*test.end() << std::endl;
		std::cout << &*test.end() << std::endl;
		int *p = NULL;
		std::cout << p << std::endl;
		*/

		
		/*std::map<int, double> test;
		test.insert(std::make_pair(1, 1.1));
		test.insert(std::make_pair(2, 2.2));
		for (std::map<int, double>::iterator i = test.begin(); i != test.end(); i++)
		{
			std::cout << (*i).first << "    " << (*i).second << std::endl;
		}
		for (std::map<int, double>::iterator i = test.begin(); i != test.end(); i++)
		{
			std::cout << i->first << "    " << i->second << std::endl;
		}
		std::cout << test[100] << std::endl;

		std::map<int, double> test2;
		test2[3] = 3.0;
		std::cout << test2.at(3) << std::endl;
		//std::cout << test2.at(42424) << std::endl;
		std::cout << &*test2.end()  << std::endl;
		test.insert(test2.begin(), test2.end());
		container_print(test);
		test2 = test;
		std::cout << &*test.end() << "  " << &*test2.end() << std::endl;//_endNode가 다르다는것을 간접적으로 알수있음.
		std::map<int, double>::iterator t = test.begin();
		//t--;
		std::map<int, double>::iterator t2 = test.end();
		//t2++;
		std::cout << t2->first <<"    "<< t2->second << std::endl;
		test[t2->first] = 42;
		std::cout << t2->first <<"    "<< t2->second << std::endl;
		std::cout << t2->first <<"    "<< test[t2->first] << std::endl;//endNode는 유효한 노드로 쳐주지 않으니까 이러한 현상이 발생하는듯*/
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}