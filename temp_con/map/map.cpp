#include <set>
#include <iostream>
#include <map>
#include "map.hpp"
#include <algorithm>

template <class T>
void container_print(T container)
{
	
	for (typename T::iterator iter = container.begin(); iter != container.end(); iter++)
		std::cout << "|키= " << iter->first << ", 값 =" << iter->second << "|  ";
	std::cout << std::endl;
}

void func()
{
	
	std::cout << "디폴트생성자를 호출해보고, insert()멤버함수를 호출해봅니다\n" << std::endl;
	ft::map<int, int> test;
	ft::pair< ft::map<int, int>::iterator, bool> Pair = test.insert(ft::make_pair(3, 3));
	std::cout << Pair.first->first << std::endl;
	std::cout << "\n디폴트생성자를 호출해보고, insert()멤버함수를 호출해봅니다" << std::endl;
	
	
	
	std::cout << "대입연산자를 호출해봅니다\n" << std::endl;
	ft::map<int, double> test2;
	test2.insert(ft::make_pair(1, 1.1));
	test2.insert(ft::make_pair(2, 2.2));
	container_print(test2);
	
	std::cout << "존재하지 않는 key 100에 대하여, test2[100] = " << test2[100] << std::endl;
	std::cout << "존재하지 않는 key 100에 대하여, test2.at(100) = " << test2.at(100) << std::endl;// <- 이 한쌍으로 실험해보기... 어떻게 동작하는지 알수있음
	
	ft::map<int, double> test3;
	test3[3] = 3.0;
	std::cout << test3.at(3) << std::endl;
	
	//std::cout << &(*test3.end())  << std::endl; <- 왜 std::는 되고 ft::는 안되는건지...?
	
	test2.insert(test3.begin(), test3.end());
	container_print(test2);
	std::cout << "**********" << test2.size() << std::endl;
	//ft::map<int, double>::BTreeNode *w = test2.begin().base();
	//std::cout<< w->value.first << std::endl;
	//std::cout<< w->right->value.first << std::endl;//여기선 잘 나오는데 밑에 어디선가 트리가 꼬여버린듯...?
	//std::cout<< w->right->right->value.first << std::endl;
	//std::cout<< w->right->right->left->value.first << std::endl;
	//std::cout << "*******" <<std::endl;
	test3 = test2;
	std::cout << "복사가 잘 되었는지 체크해봅시다" << std::endl;
	std::cout << "test의 내부값 : "; container_print(test3);
	std::cout << "test3의 내부값: "; container_print(test3);
	//std::cout << &*test2.end() << "  " << &*test3.end() << std::endl; //_endNode가 다르다는것을 간접적으로 알수있음.(복사생성자호출해도 _endNode는 복사가 안됨)
	ft::map<int, double>::iterator iter = test2.begin();
	//t--; //segmentation fault
	ft::map<int, double>::iterator iter2 = test2.end();
	//t2++; //segmentation fault
	std::cout << iter2->first <<"    "<< iter2->second << std::endl;
	test2[iter2->first] = 42;
	std::cout << iter2->first << std::endl;
	container_print(test2);
	std::cout << iter2->first <<"    "<< iter2->second << std::endl;
	std::cout << iter2->first <<"    "<< test2[iter2->first] << std::endl;//endNode는 유효한 노드로 쳐주지 않으니까 이러한 현상이 발생하는듯
	container_print(test2);
	std::cout << "\n대입연산자를 호출해봅니다 끝!!!!!!!" << std::endl;
	
	std::cout << "\nCapacity에 해당하는 멤버함수들을 테스트해봅니다\n" << std::endl;
	std::cout << "test2의 size : " << test2.size()<< " test2의 empty : " << test2.empty() << " test2의 max_size : " << test2.max_size()<< std::endl;
	std::cout << "test2의 내부값: "; container_print(test2);
	std::cout << "test3의 size : " << test3.size()<< " test3의 empty : " << test3.empty() << " test3의 max_size : " << test3.max_size()<< std::endl;
	std::cout << "test3의 내부값: "; container_print(test3);
	std::cout << "\nCapacity에 해당하는 멤버함수들을 테스트해봅니다 끝!!!!" << std::endl;
	


	
	std::cout << "Modifiers 멤버함수를 테스트해봅니다." << std::endl;
	ft::map<int, double> test4, test5;
	test4.clear();
	test4.insert(ft::make_pair(42, 42.0));
	test4.insert(ft::make_pair(42, 42.0));
	test4.insert(ft::make_pair(10, 10.0));
	test4.insert(ft::make_pair(144, -10.0));
	test4.insert(ft::make_pair(55, 10.0));
	std::cout << "test4의 내부: ";container_print(test4);
	test5 = test4;
	test4.clear();
	std::cout << "test4의 내부(비어있어야함): "; container_print(test4);
	ft::map<int, double>::iterator s_iter = test5.begin();
	test5.insert(s_iter, ft::make_pair(33, 3));
	std::cout << "test5의 내부({33,3}쌍을 추가함): "; container_print(test5);
	s_iter = test5.begin();
	ft::map<int, double>::iterator e_iter = test5.end();
	s_iter++; 
	e_iter--;
	std::cout << "test5의 내부: "; container_print(test5);
	test5.erase(s_iter, e_iter);
	std::cout << "test5의 내부(2번째요소부터 마지막요소 직전까지 삭제됨): "; container_print(test5);
	std::cout << "test5의 내부(swap하기 전): "; container_print(test5);
	ft::map<int, double> test6;
	test5.swap(test6);
	std::cout << "test5의 내부(swap한 뒤): ";container_print(test5);
	std::cout << "test6의 내부: ";container_print(test6);
	

	
	std::cout <<"Lookup을 테스트해봅니다" << std::endl;
	ft::map<int, double> test7;
	test7.insert(ft::make_pair(42, 42.0));
	test7.insert(ft::make_pair(42, 42.0));
	test7.insert(ft::make_pair(10, 10.0));
	test7.insert(ft::make_pair(144, -10.0));
	test7.insert(ft::make_pair(55, 10.0));
	std::cout << test7.count(42) << std::endl;
	std::cout << test7.count(1004) << std::endl;

	std::cout <<"Lookup을 테스트해봅니다 끝!!!!!!!" << std::endl;
	

	
	std::cout <<"Observers를 테스트해봅니다\n" << std::endl;
	ft::map<int, double> test8;
	test8.insert(ft::make_pair(42, 21.0));
	test8.insert(ft::make_pair(42, 42.0));
	test8.insert(ft::make_pair(10, 10.0));
	test8.insert(ft::make_pair(144, -10.0));
	test8.insert(ft::make_pair(55, 10.0));
	ft::map<int, double>::key_compare kcomp = test8.key_comp();
	std::cout << kcomp(3, 100) << std::endl;
	std::cout << kcomp(100, 3) << std::endl;
	ft::map<int, double>::value_compare vcomp = test8.value_comp();
	std::cout << vcomp(ft::make_pair(3, 10000), ft::make_pair(100000, 42)) << std::endl;
	std::cout << vcomp(ft::make_pair(100000, 42), ft::make_pair(3, 100000)) << std::endl;
	std::cout <<"\nequal_range 함수를 테스트해봅니다\n" << std::endl;
	ft::pair< ft::map<int, double>::iterator, ft::map<int, double>::iterator > eq = test8.equal_range(42);
	container_print(test8);
	if (eq.first == eq.second)
		std::cout << "target을 못찾음" << std::endl;
	else
	{
		std::cout << eq.first->first << "      " << eq.first->second << std::endl;
		std::cout << eq.second->first << "      " << eq.second->second << std::endl;
	}
	eq = test8.equal_range(42424242);
	if (eq.first == eq.second)
		std::cout << "target을 못찾음" << std::endl;
	else
	{
		std::cout << eq.first->first << "      " << eq.first->second << std::endl;
		std::cout << eq.second->first << "      " << eq.second->second << std::endl;
	}
	std::cout <<"\nObservers를 테스트해봅니다 끝!!!!!!!" << std::endl;
	

	
	std::cout << "비멤버 함수를 테스트해봅니다\n" << std::endl;
	ft::map<int, double> test9, test10;
	test9.insert(ft::make_pair(42, 42.0));
	test9.insert(ft::make_pair(42, 42.0));
	test9.insert(ft::make_pair(10, 10.0));
	test9.insert(ft::make_pair(144, -10.0));
	test9.insert(ft::make_pair(55, 10.0));
	test10 = test9;
	container_print(test9);
	container_print(test10);
	std::cout << "test9 == test10 : " << (test9 == test10) << std::endl;
	std::cout << "test9 != test10 : " << (test9 != test10) << std::endl;
	std::cout << std::endl;
	test10[200] = 42;
	container_print(test9);
	container_print(test10);
	std::cout << "test9 == test10 : " << (test9 == test10) << std::endl;
	std::cout << "test9 != test10 : " << (test9 != test10) << std::endl;
	std::cout << "test9  < test10 : " << (test9 < test10) << std::endl;

	std::swap(test9, test10);
	container_print(test9);
	container_print(test10);
	std::cout << "\n비멤버 함수를 테스트해봅니다 끝!!!" << std::endl;
	

	/*
	std::cout << "reverse_iterator를 테스트해봅니다" << std::endl;
	ft::map<int, double> test11;
	test11.insert(ft::make_pair(42, 42.0));
	test11.insert(ft::make_pair(42, 42.0));
	test11.insert(ft::make_pair(10, 10.0));
	test11.insert(ft::make_pair(144, -10.0));
	test11.insert(ft::make_pair(55, 10.0));
	ft::map<int, double>::reverse_iterator r_iter = test11.rbegin();
	for (; r_iter != test11.rend(); r_iter++)
	{	std::cout << "|키= " << r_iter->first << ", 값 =" << r_iter->second << "|  ";}
	std::cout << std::endl;
	*/
}
int main()
{
	try
	{
		func();
		while (1) {} 
	}
	catch (std::exception &e)
	{
		std::cout << "\n" << e.what() << std::endl;
	}
	return 0;
}