#include "Pony.hpp"

int main(void)
{
	std::cout<<"before ponyOnTheHeap call"<<std::endl;
    ponyOnTheHeap();
	std::cout<<"after ponyOnTheHeap call"<<std::endl;
	std::cout<<"\n\n"<<"before ponyOnTheStack call"<<std::endl;
    ponyOnTheStack();
	std::cout<<"after ponyOnTheStack call"<<std::endl;
    return (0);
}
