#include <iostream>

void ft_each(int &ref){
	++ref;
}

void iter (int *arr, int length, void (*Fptr)(int &)){
	for (int i = 0; i < length; i++){
		Fptr(arr[i]);
	}
}

int main(void){
    int *arr = new int[10];
    for(int i = 0 ; i < 10; i++){
        arr[i] = i;
    }
    for(int i = 0 ; i < 10; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    iter(arr, 10, ft_each);
    
    for(int i = 0 ; i < 10; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    delete []arr;
    return 0;
}