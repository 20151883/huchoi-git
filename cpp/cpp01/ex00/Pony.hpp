#include <iostream>

class Pony{
	private:
		std::string color;
		std::string name;
		std::string price;
	public:
		void	define_pony(std::string color="no color", std::string name="no name", std::string price="no price");
		void	print_information();
		~Pony();
};
void	ponyOnTheHeap(void);
void	ponyOnTheStack(void);
