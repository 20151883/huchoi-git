#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <exception>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>
#include <map>
#include <sstream>
#include <fstream>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <cstring>
#include <algorithm>

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
void chunk_check(std::string &src, int pos)
{
	int start = pos;
	int end;
	long len;
	std::string body;

	while (1)
	{
		end = src.find_first_of("\r", start) + 1;
		len = hexaStringToLong(src.substr(start, end - start -1));
		std::cout << "start : " << start << "   end: " << end << std::endl;
		std::cout << "len : " << len << std::endl;
		if (end == std::string::npos || (src[start] == '0' && start == src.size() - 1))
			break;
		start = end + 1;
		end = src.find_first_of("\r", start) - 1;
		std::cout << "start : " << start << "   end: " << end << std::endl;
		if (len == (end - start + 1))
			std::cout << "ok\n" << std::endl;
		else
			std::cout << "error\n" << std::endl;
		body += src.substr(start, end - start + 1);
		start = end + 3;
		sleep(1);
	}
	std::cout << body << std::endl;
}

int main(void)
{
	std::string test = "this\r\n\r\n5\r\nthiss\n\r\n3\r\ntt\r\n0";
	chunk_check(test, 8);
}