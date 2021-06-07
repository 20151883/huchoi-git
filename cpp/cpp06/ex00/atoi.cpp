#include <iostream>
#include <string>
#include <cstdio>

int main()
{
	std::string int_val = "123";
	std::string float_val = "123.45";
	std::string double_val = "123";

	int i = std::stoi(int_val);
	float f = std::stof(float_val);
	double d = std::stod(double_val);

	printf("%d\n", i);
	printf("%.1ff\n", f);
	printf("%.1lf\n", d);
	return 0;
}
