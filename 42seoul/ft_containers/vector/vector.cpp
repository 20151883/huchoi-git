#include "vector.hpp"

#include <unistd.h>
#include <ctime>
#include <cstdlib>

template <typename Container>
void container_print(Container src)
{
    for (typename Container::iterator i = src.begin(); i != src.end(); i++)
        std::cout << *i <<"; ";
    std::cout << std::endl;
}

int main(void)
{
    srand(time(NULL));

    try{

        /*
        std::cout << "\n여러가지 생성자를 통해서 객체를 생성해 봅니다 시작" << std::endl;
        ft::vector<int> vec;
        ft::vector<int> vec2(10, 42);
        ft::vector<int> vec3(vec2.begin(), vec2.end());
        ft::vector<int> vec4(vec2);
        std::cout<<"vec2의 내부를 출력합니다" << std::endl;
        container_print(vec2);
        std::cout<<"vec2의 size = "<< vec2.size() << "capacity : "<< vec2.capacity() <<std::endl;
        std::cout<<"\nvec3의 내부를 출력합니다"<<std::endl;
        container_print(vec3);
        std::cout<<"vec3의 size = "<< vec3.size() << "capacity : "<< vec3.capacity() <<std::endl;
        std::cout<<"\nvec4의 내부를 출력합니다"<<std::endl;
        container_print(vec4);
        std::cout<<"vec4의 size = "<< vec4.size() << "capacity : "<< vec4.capacity() <<std::endl;

        std::vector<int>::iterator t;//std::랑 ft::랑 결과가 다르게 나옴.
        std::cout<<*t++<<std::endl;
        
        std::cout << "여러가지 생성자를 통해서 객체를 생성해 봅니다 끝!!!!!!" << std::endl;
        */

        /*
        std::cout << "\n표준 Algorithms 함수와의 호환성을 체크해 봅시다" << std::endl;
        ft::vector<int> vec(10);    
        for(ft::vector<int>::Iterator iter =  vec.begin(); iter != vec.end();  iter++)
            *iter = rand() % 100;
        std::cout<<"std::sort() 이전의 상태는 다음과 같습니다."<<std::endl;
        container_print(vec);

        std::sort(vec.begin(), vec.end(), std::less<int>());
        std::cout<<"std::sort()의 결과는 다음과 같습니다."<<std::endl;
        container_print(vec);
        
        std::cout << "\n총 "<<std::distance(vec.begin(), vec.end())<<"개의 element가 있습니다.\n" << std::endl;
        
        std::cout << "표준 Algorithms 함수와의 호환성을 체크해 봅시다 끝!!!!!!.\n" << std::endl;
        //또 다른 알고리즘 함수 뭐가 있더라...?
       */

        /*
        std::cout << "\ncapacity()함수를 테스트 해봅니다" <<std::endl;
        ft::vector<int> vec(10);    
        vec.reserve(20);
        std::cout<<"\nvec의 size : "<< vec.size() << "이고 capacity : "<< vec.capacity() <<"\n" << std::endl;
        std::cout << "capacity()함수를 테스트 해봅니다 끝!!!!\n" <<std::endl;
        */
        
        /*
        std::cout << "\ninsert()함수와 erase()함수를 체크해봅시다." << std::endl;
        ft::vector<int>::iterator iter;
        ft::vector<int> vec(10, 42);
        iter = vec.insert(vec.begin(), 1000);
        container_print(vec);
        iter = vec.insert(iter, -1);
        container_print(vec);
        iter = vec.insert(iter, -2);
        container_print(vec);
        iter = vec.insert(iter, -3);
        container_print(vec);
        iter = vec.insert(iter, -4);
        container_print(vec);
        std::cout << "***********************************************" << std::endl;
        
        iter = vec.erase(vec.begin());
        container_print(vec);
        iter = vec.erase(iter);
        container_print(vec);
        iter = vec.erase(iter);
        container_print(vec);
        iter = vec.erase(iter);
        container_print(vec);
        iter = vec.erase(iter);
        container_print(vec);

        std::cout << "***********************************************" << std::endl;
        
        ft::vector<int> vec2(10);
        for(ft::vector<int>::Iterator iter =  vec2.begin(); iter != vec2.end();  iter++)
            *iter = rand() % 100;
        std::sort(vec2.begin(), vec2.end(), std::less<int>());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        iter = vec2.erase(vec2.begin() + rand() % vec2.size());
        container_print(vec2);
        std::cout << "insert()함수와 erase()함수를 체크해봅시다 끝!!!!!\n" << std::endl;
        */
        
        /*
        std::cout << "\nft::vector<>::iterator을 테스트 해 봅시다" << std::endl;
        ft::vector<int> vec(10);
        for(ft::vector<int>::Iterator iter =  vec.begin(); iter != vec.end();  iter++)
            *iter = rand() % 100;
        std::sort(vec.begin(), vec.end());
        container_print(vec);
        ft::vector<int>::Iterator iter1 = vec.begin();
        std::cout << *iter1 << std::endl;
        iter1.operator++();
        std::cout << *iter1 << std::endl;
        iter1.operator++();
        iter1.operator--();
        std::cout << *iter1 << std::endl;
        iter1.operator--();
        std::cout << *iter1 << std::endl;
        std::cout << "******************************" << std::endl;
        ft::vector<int>::Iterator iter2 = vec.begin();
        std::cout << "iter1 == iter2 의 결과는: " << (iter1 == iter2) << std::endl;
        std::cout << "iter++ 연산이 실행" << std::endl;
        iter1++;
        std::cout << "iter1 == iter2 의 결과는: " << (iter1 == iter2) << std::endl;
        std::cout << "iter1 < iter2 의 결과는: " << (iter1 < iter2) << std::endl;
        std::cout << "iter1 > iter2 의 결과는: " << (iter1 > iter2) << std::endl;
        std::cout << "ft::vector<>::iterator을 테스트 해 봅시다. 끝!!!!!!!!\n" << std::endl;
        */

        /*
        std::cout<<"\nvector.resize()함수와 vector.swap() 함수를 테스트 해봅시다."<<std::endl;
        ft::vector<int> vec(10, 42);
        //vec.resize(11, 100);
        std::cout << "swap 이전 vec객체와 vec2객체를 출력"<<std::endl;
        container_print(vec);
        ft::vector<int> test(vec);
        test.resize(5, 42);
        container_print(test);

        test.swap(vec);
        std::cout << "\nswap 이후 vec객체와 vec2객체를 출력"<<std::endl;
        container_print(vec);
        container_print(test);
        std::cout<<"\nvector.resize()함수와 vector.swap() 함수를 테스트 해봅시다. 끝!!!!!!!\n"<<std::endl;
        */

        /*
        std::cout<<"\n비멤버 함수 test를 테스트해봅시다."<<std::endl;
        ft::vector<int> alice;
        alice.push_back(1);
        alice.push_back(2);
        alice.push_back(3);
        ft::vector<int> bob;
        bob.push_back(7);
        bob.push_back(8);
        bob.push_back(9);
        bob.push_back(10);
        ft::vector<int> eve;
        eve.push_back(1);
        eve.push_back(2);
        eve.push_back(3);

        std::cout << std::boolalpha;
    
        // Compare non equal containers
        std::cout << "alice == bob returns " << (alice == bob) << '\n';
        std::cout << "alice != bob returns " << (alice != bob) << '\n';
        std::cout << "alice <  bob returns " << (alice < bob) << '\n';
        std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
        std::cout << "alice >  bob returns " << (alice > bob) << '\n';
        std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
    
        std::cout << '\n';
    
        // Compare equal containers
        std::cout << "alice == eve returns " << (alice == eve) << '\n';
        std::cout << "alice != eve returns " << (alice != eve) << '\n';
        std::cout << "alice <  eve returns " << (alice < eve) << '\n';
        std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
        std::cout << "alice >  eve returns " << (alice > eve) << '\n';
        std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
        std::cout<<"비멤버 함수 test를 테스트해봅시다. 끝!!!!!\n"<<std::endl;
        */

        
        //std::vector<int> t;
        //std::cout << t.back() << std::endl;
        std::vector<int> vec(10);
        for(std::vector<int>::iterator iter =  vec.begin(); iter != vec.end();  iter++)
            *iter = rand() % 100;
        std::sort(vec.begin(), vec.end());
        container_print(vec);
        std::vector<int>::reverse_iterator i = vec.rbegin();
        i += 3;
        std::cout << *i <<"  "<< &*i <<std::endl;
        std::vector<int>::iterator test = i.base();//ptr자체를 반환하는게 맞음.
        std::cout << *test <<"  "<< &*test <<std::endl;
        test++;
        std::cout << *test <<"  "<< &*test <<std::endl;
        
        ft::vector<int> a(10);
        std::cout << a.capacity() << std::endl;
        std::cout << a.size() << std::endl;
        a.clear();
        std::cout << a.capacity() << std::endl;
        std::cout << a.size() << std::endl;
        a.assign(10, 42);
        
         ft::vector<int>::iterator iter2 = a.end();
         iter2++;
         iter2++;
         iter2++;
         iter2++;
         iter2++;//map과는 다르게 세그폴트가 안남...
         
       /*
       std::cout << "암시적 형변환에 대해 테스트 해봅시다." << std::endl;
        ft::vector<int> test(3);
        //std::cout << (test == 3) << std::endl;
        std::cout << "암시적 형변환은 허용이 되지 않습니다." << std::endl;
        */
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}