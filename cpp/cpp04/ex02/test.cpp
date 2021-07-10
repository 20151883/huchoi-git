#include <vector>
#include <iostream>

int main(void)
{
    std::string *p1,*p2,*p3;
    std::string s1,s2,s3;
    s1 = "one";
    s2 = "two";
    s3 = "three";

    p1 = &s1;
    p2 = &s2;
    p3 = &s3;
    std::vector<std::string> test;
    test.push_back(s1);
    test.push_back(s2);
    test.push_back(s3);
    std::cout<<&test[2]<<std::endl;
    std::cout<<&s3<<std::endl;
    //결론: 켄터이너는 객체를 보관할때 깊은 복사본이 아니라 얕은 복사본을 저장한다.(복사의 대상이 데이터가 아니고 주소이다!)
    //      아니다. 깊은 복사(주소값의 복사가 아닌 값의 복사)컨테이너가 초기에 저장하기로 한 값의 자료형이 있을것인데, 해당 자료형의 값을 복사(DUPLICATE)해서 저장한다. 즉, 값의 복사이다. (이게 맞는듯) 
    //test2
    std::vector<std::string> test2(test);
    std::cout<<&test[2]<<std::endl;
    std::cout<<&test2[2]<<std::endl;
    std::cout<<&s3<<std::endl;

    //test3
    std::vector<int> arr;
    int n1=1,n2=2,n3=3;
    arr.push_back(n1);
    arr.push_back(n2);
    arr.push_back(n3);
    
    std::cout<<"this is test"<<std::endl;
    std::cout<<&n1<<std::endl;
    std::cout<<&(arr[0])<<std::endl;
    //아마도 ex02에서 컨테이너가 저장하는 대상은 주소값이겠다... 
    return (0);
}