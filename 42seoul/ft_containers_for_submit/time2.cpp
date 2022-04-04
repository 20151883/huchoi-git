#include "vector.hpp"
#include <iostream>
#include <chrono>
#include <ctime>
#include "etc.hpp"
#include <map>
int main()
{
    {std::cout << "namespace ft 결과" << std::endl;

    ft::vector<int> test;
	for (int  i =0; i < 300000 ; i++){
		test.push_back(i);
	}
    std::__1::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	ft::vector<int> test2;
	test2 = test;
	// Some computation here
    std::__1::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "[elapsed time: " << elapsed_seconds.count() << "s]\n\n\n\n";
}
    {std::cout << "namespace std의 결과" << std::endl;
    std::vector<int> test;
	for (int  i =0; i < 300000 ; i++){
		test.push_back(i);
	}
    std::__1::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::vector<int> test2;
	test2 = test;
	// Some computation here
    std::__1::chrono::system_clock::time_point end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "[elapsed time: " << elapsed_seconds.count() << "s]\n";}
}
