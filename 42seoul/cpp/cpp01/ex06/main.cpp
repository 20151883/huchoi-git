#include "Karen.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
		return (1);
	}
	Karen test;
	int flag = -1;
	const char *arr[4] = {"DEBUG","INFO","WARNING","ERROR"};
	for (int i = 0; i < 4;i++)
	{
		if (std::string(arr[i]) == std::string(argv[1]))
		{
			flag = i;
		}
	}
	switch (flag)
	{
		case 0:
			std::cout<<"[ DEBUG ]"<<std::endl;
			test.complain("DEBUG");
			std::cout<<"[ INFO ]"<<std::endl;
			test.complain("INFO");
			std::cout<<"[ WARNING ]"<<std::endl;
			test.complain("WARNING");
			std::cout<<"[ ERROR ]"<<std::endl;
			test.complain("ERROR");
			break;
		case 1:
			std::cout<<"[ INFO ]"<<std::endl;
			test.complain("INFO");
			std::cout<<"[ WARNING ]"<<std::endl;
			test.complain("WARNING");
			std::cout<<"[ ERROR ]"<<std::endl;
			test.complain("ERROR");
			break;
		case 2:
			std::cout<<"[ WARNING ]"<<std::endl;
			test.complain("WARNING");
			std::cout<<"[ ERROR ]"<<std::endl;
			test.complain("ERROR");
			break;
		case 3:
			std::cout<<"[ ERROR ]"<<std::endl;
			test.complain("ERROR");
			break;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
			break;
	}
	return (0);
}
