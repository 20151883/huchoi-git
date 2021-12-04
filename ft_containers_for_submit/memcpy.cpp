#include "vector.hpp"
#include <iostream>
#include <cstring>

class Test{
	public:
		int *ptr;//서로 다른 객체라면 이
	public:
		Test():ptr(NULL){}//디폴트생성자
		Test(int *ptr){this->ptr = ptr;}
};

int main(){
	int num = 3;
	Test test(&num);
	ft::vector<Test> v1;
	v1.push_back(test);

	 ft::vector<Test> v2;
	 v2 = v1;

	 ft::vector<Test>::iterator iter1 = v1.begin();
	 ft::vector<Test>::iterator iter2 = v2.begin();

	 std::cout << iter1->ptr <<"   " << iter2->ptr << std::endl;
	 std::cout << *(iter1->ptr) <<"   " << *(iter2->ptr) << std::endl;

	Test *ptr1 = iter1.base();
	Test *ptr2 = iter2.base();

	std::cout << ptr1->ptr <<"   " << ptr2->ptr << std::endl;
	std::cout << *(ptr1->ptr) <<"   " << *(ptr2->ptr) << std::endl;

}
