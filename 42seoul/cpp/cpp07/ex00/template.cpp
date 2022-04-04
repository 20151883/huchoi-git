#include <iostream>

int ft_max(int arg1, int arg2){
    if (arg1 > arg2)
        return arg1;
    else
        return arg2;
}

template <typename T>
T template_max(T arg1, T arg2){
    if (arg1 > arg2)
        return arg1;
    else
        return arg2;
}

int main(void){
    std::cout << ft_max(3, 4) << std::endl;
    return 0;
}