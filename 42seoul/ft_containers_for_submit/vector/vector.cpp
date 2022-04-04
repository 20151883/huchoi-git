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

void func()
{
        ft::vector<int> v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        ft::reverse_iterator<ft::vector<int>::iterator> r_iter1 = v.rbegin();
        for (std::size_t i = 0; i != v.size(); ++i)
            std::cout << r_iter1[i] << ' ';
        std::cout << '\n';
        
        std::cout << "\n여러가지 생성자를 통해서 객체를 생성해 봅니다." << std::endl;
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
        vec2.clear();
        std::cout << vec2.size() << std::endl;
        std::cout<<"vec4의 size = "<< vec4.size() << "capacity : "<< vec4.capacity() <<std::endl;

        //std::vector<int>::iterator t;std::랑 ft::랑 결과(초기화하는 값이 다르다는 뜻)가 다르게 나옴.
        //std::cout<<*t<<std::endl;
        
        std::cout << "여러가지 생성자를 통해서 객체를 생성해 봅니다 끝!!!!!!" << std::endl;
        
        std::cout << "\n표준 Algorithms 함수와의 호환성을 체크해 봅시다" << std::endl;
        ft::vector<int> vec5(10);    
        for(ft::vector<int>::Iterator iter1 =  vec5.begin(); iter1 != vec5.end();  iter1++)
            *iter1 = rand() % 100;
        std::cout<<"std::sort() 이전의 상태는 다음과 같습니다."<<std::endl;
        container_print(vec5);
        std::sort(vec5.begin(), vec5.end(), std::less<int>());
        std::cout<<"std::sort()의 결과는 다음과 같습니다."<<std::endl;
        container_print(vec5);
        std::cout << "\n총 "<<std::distance(vec5.begin(), vec5.end())<<"개의 element가 있습니다.\n" << std::endl;
        std::cout << "표준 Algorithms 함수와의 호환성을 체크해 봅시다 끝!!!!!!.\n" << std::endl;
        //또 다른 알고리즘 함수 뭐가 있더라...?
       
        std::cout << "\ncapacity()함수를 테스트 해봅니다" <<std::endl;
        ft::vector<int> vec6(10);    
        vec6.reserve(20);
        std::cout<<"\nvec의 size : "<< vec6.size() << "이고 capacity : "<< vec6.capacity() <<"\n" << std::endl;
        std::cout << "capacity()함수를 테스트 해봅니다 끝!!!!\n" <<std::endl;
        
        std::cout << "\ninsert()함수와 erase()함수를 체크해봅시다." << std::endl;
        ft::vector<int>::iterator iter2;
        ft::vector<int> vec7(10, 42);
        iter2 = vec7.insert(vec7.begin(), 1000);
        container_print(vec7);
        iter2 = vec7.insert(iter2, -1);
        container_print(vec7);
        iter2 = vec7.insert(iter2, -2);
        container_print(vec7);
        iter2 = vec7.insert(iter2, -3);
        container_print(vec7);
        iter2 = vec7.insert(iter2, -4);
        container_print(vec7);
        std::cout << "***********************************************" << std::endl;
        
        iter2 = vec7.erase(vec7.begin());
        container_print(vec7);
        iter2 = vec7.erase(iter2);
        container_print(vec7);
        iter2 = vec7.erase(iter2);
        container_print(vec7);
        iter2 = vec7.erase(iter2);
        container_print(vec7);
        iter2 = vec7.erase(iter2);
        container_print(vec7);

        std::cout << "***********************************************" << std::endl;
        
        ft::vector<int> vec8(10);
        ft::vector<int>::Iterator iter3;
        for(iter3 =  vec8.begin(); iter3 != vec8.end();  iter3++)
            *iter3 = rand() % 100;
        std::sort(vec8.begin(), vec8.end(), std::less<int>());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        iter3 = vec8.erase(vec8.begin() + rand() % vec8.size());
        container_print(vec8);
        std::cout << "insert()함수와 erase()함수를 체크해봅시다 끝!!!!!\n" << std::endl;
        
        std::cout << "\nft::vector<>::iterator을 테스트 해 봅시다" << std::endl;
        ft::vector<int> vec9(10);
        ft::vector<int>::Iterator iter4;
        for(iter4 =  vec9.begin(); iter4 != vec9.end();  iter4++)
            *iter4 = rand() % 100;
        std::sort(vec9.begin(), vec9.end());
        container_print(vec9);
        ft::vector<int>::Iterator iter5 = vec9.begin();
        std::cout << *iter5 << std::endl;
        iter5.operator++();
        std::cout << *iter5 << std::endl;
        iter5.operator++();
        iter5.operator--();
        std::cout << *iter5 << std::endl;
        iter5.operator--();
        std::cout << *iter5 << std::endl;
        std::cout << "******************************" << std::endl;
        ft::vector<int>::Iterator iter6 = vec9.begin();
        std::cout << "iter5 == iter6 의 결과는: " << (iter5 == iter6) << std::endl;
        std::cout << "iter5++ 연산이 실행" << std::endl;
        iter5++;
        std::cout << "iter5 == iter6 의 결과는: " << (iter5 == iter6) << std::endl;
        std::cout << "iter5 < iter6 의 결과는: " << (iter5 < iter6) << std::endl;
        std::cout << "iter5 > iter6 의 결과는: " << (iter5 > iter6) << std::endl;
        std::cout << "ft::vector<>::iterator을 테스트 해 봅시다. 끝!!!!!!!!\n" << std::endl;
    
        std::cout<<"\nvector.resize()함수와 vector.swap() 함수를 테스트 해봅시다."<<std::endl;
        ft::vector<int> vec10(10, 42);
        //vec10.resize(11, 100);
        std::cout << "swap 이전 vec객체와 vec2객체를 출력"<<std::endl;
        container_print(vec10);
        ft::vector<int> test(vec10);
        test.resize(5, 42);
        container_print(test);
        std::cout << "******************************" << std::endl;
        test.swap(vec10);
        std::cout << "\nswap 이후 vec객체와 vec2객체를 출력"<<std::endl;
        container_print(vec10);
        container_print(test);
        std::cout<<"\nvector.resize()함수와 vector.swap() 함수를 테스트 해봅시다. 끝!!!!!!!\n"<<std::endl;
        

        
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
        

        
        //std::vector<int> t;
        //std::cout << t.back() << std::endl;
        
        std::vector<int> vec11(10);
        std::vector<int>::iterator iter7;
        for(iter7 =  vec11.begin(); iter7 != vec11.end();  iter7++)
            *iter7 = rand() % 100;
        std::sort(vec11.begin(), vec11.end());
        container_print(vec11);
        
        ft::vector<int> a(10);
        std::cout << a.capacity() << std::endl;
        std::cout << a.size() << std::endl;
        a.clear();
        std::cout << a.capacity() << std::endl;
        std::cout << a.size() << std::endl;
        a.assign(10, 42);
        
        ft::vector<int>::iterator iter8 = a.end();
        iter8++;
        iter8++;
        iter8++;
        iter8++;
        iter8++;//map과는 다르게 세그폴트가 안남...
        std::cout << "암시적 형변환에 대해 테스트 해봅시다." << std::endl;
        //ft::vector<int> test(3);
        //std::cout << (test == 3) << std::endl;
        std::cout << "암시적 형변환은 허용이 되지 않습니다." << std::endl;
        ft::vector<int> temp;
        temp.push_back(1);
        temp.push_back(3);
        temp.push_back(2);
        ft::vector<int>::iterator temp_iter = temp.begin();
        std::cout << (temp_iter > (temp_iter + 1)) << std::endl;
        std::cout << ((temp_iter + 1) > (temp_iter + 2)) << std::endl;
}
int main(void)
{
    srand(time(NULL));

    try{
        func();
        while (1) {}
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
        return 1;
    }
    return 0;
}