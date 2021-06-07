#include <iostream>
#include <sstream>

int main()
{
	std::string test;

	int digit = 0;
	char *str;
	std::getline (std::cin,test);
	std::stringstream ssInt(test.c_str());
	ssInt >> digit;

	float flo = 0.0;
	std::getline (std::cin,test);
	std::stringstream ssFloat(test.c_str());
	ssFloat >> flo;

	double dou = 0.0;
	std::getline (std::cin,test);
	std::stringstream ssDouble(test.c_str());
	ssDouble >> dou;

	if (!ssInt.fail())
	{
		std::cout <<"int 문자열"<< ssInt.str() << std::endl;
		std::cout <<"int 숫자값"<< digit << std::endl;
	}
	if (!ssDouble.fail())
	{
		std::cout <<"float문자열"<<ssFloat.str() << std::endl;
		std::cout <<"float숫자값"<<flo << std::endl;
	}
	if (!ssDouble.fail())
	{
		std::cout <<"double문자열"<< ssDouble.str() << std::endl;
		std::cout <<"double숫자값"<< dou << std::endl;
	}
	return 0;
}
