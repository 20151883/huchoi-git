#include "Pony.hpp"

int main(void)
{
	std::cout<<"**************************"<<std::endl;
	std::cout<<"before ponyOnTheHeap call"<<std::endl;
    ponyOnTheHeap();
	std::cout<<"after ponyOnTheHeap call"<<std::endl;
	std::cout<<"**************************"<<std::endl;
	std::cout<<"\n\n**************************"<<std::endl;
	std::cout<<"before ponyOnTheStack call"<<std::endl;
    ponyOnTheStack();
	std::cout<<"after ponyOnTheStack call"<<std::endl;
	std::cout<<"**************************"<<std::endl;

    return (0);
}
