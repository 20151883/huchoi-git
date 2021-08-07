#include "vector.hpp"

#include <unistd.h>
#include <ctime>
#include <cstdlib>

int main(void)
{
    srand(time(NULL));

    try{
        //ft::vector<int> vec;

        /*ft::vector<int> vec2(10, 42);
        for (unsigned int i = 0; i < vec2.size(); i++)
            std::cout<<vec2[i]<<"    "<<i<<std::endl;
        std::cout<<vec2.size()<<std::endl;*/

        /*
        ft::vector<int> vec(10, 42);
        ft::vector<int> vec2(vec.begin(), vec.end());//아직 검증 못해봄
        //ft::vector<int>::Iterator j;// = vec2.begin();
        for (ft::vector<int>::Iterator i = vec2.begin(); i != vec2.end(); i++)
            std::cout << *i << "?" << std::endl;
        //std::vector<int> test;
        std::vector<int>::iterator t;//std::랑 ft::랑 결과가 다르게 나옴.
        std::cout<<*t++<<std::endl;
        */
        std::cout<<"******************"<<std::endl;
        ft::vector<int> vec(10, 42);
        //vec[9] = 43;
        // = vec.rbegin();
        //for(ft::vector<int>::reverse_iterator r_iter = vec.rbegin(); r_iter != vec.rend(); r_iter++)
        //    *r_iter = rand() % 100;
        for(ft::vector<int>::Iterator iter =  vec.begin(); iter != vec.end();  iter++)
            *iter = rand() % 100;
        for(ft::vector<int>::Iterator iter =  vec.begin(); iter != vec.end();  iter++)
            std::cout<<*iter<<", ";
        std::cout<<std::endl;
        std::distance(vec.begin(), vec.end());
        //std::vector<int> vec2(10, 42);
        std::sort(vec.begin(), vec.end(), std::less<int>());
        std::cout<<"******************"<<std::endl;
        for(ft::vector<int>::Iterator iter =  vec.begin(); iter != vec.end();  iter++)
            std::cout<<*iter<<", ";
        std::cout<<std::endl;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}