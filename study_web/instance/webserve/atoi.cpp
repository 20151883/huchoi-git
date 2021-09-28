#include <cstdlib>
#include <iostream>
#include <cmath>
#include <map>

long hexaStringToLong(const std::string &str)
{
	long ret = 0;
	std::map<char, int> map;
	char c = 'a';
	int size = str.size();
	int temp;
	for (int i = 0; i < size; i++)
	{
		if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
		{
			if (str[i] < 'a')
				temp = str[i] - '0';
			else
				temp = str[i] - 'a' + 10;
			ret += temp * pow(16, size - i -1);
		}
		else
			break;
	}
	return ret;
}

std::string longToHexaString(long src)
{
	std::string ret;
	char ch;
	while (src != 0)
	{
		ch = src % 16;
		if (ch > 10)
			ch += 'a' - 10;
		else
			ch += '0';
		ret.insert(ret.begin(), ch);
		src /= 16;
	}
	return ret;
}

int main(void)
{
	const char *arr = "5";
	long test = hexaStringToLong(std::string(arr));
	std::cout << test << std::endl;
	std::cout << longToHexaString(test) << std::endl;
	return 0;
} 