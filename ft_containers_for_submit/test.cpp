#include "vector.hpp"
#include <vector>

int main(void){
    std::vector<int> vec(3, 0);
    vec.push_back(0);
    std::cout << "size " << vec.size() << std::endl;
    std::cout << "capacity " << vec.capacity() << std::endl;
    std::cout << "max_size " << vec.max_size() << std::endl;

    int *ptr = new int;
    std::cout << *ptr << std::endl;
    return 0;
}