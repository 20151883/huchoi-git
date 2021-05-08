#include <iostream>
#include <cstring>

int main(void)
{
    //char arr[std::strlen("HI THIS IS BRAIN") + 1];
    char *arr = new char[std::strlen("HI THIS IS BRAIN") + 1];
    std::strcpy(arr, "HI THIS IS BRAIN");
    char *(&ref) = arr;//참조정보가 저장된다.
    std::cout<<arr<<std::endl;
    std::cout<<ref<<std::endl;
    delete []arr;
    return (0);
}