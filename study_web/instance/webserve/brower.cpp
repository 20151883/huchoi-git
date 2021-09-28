#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool ft_contain(const std::string &src, std::string sub)
{
	int len = sub.size();
	int size =  src.size();
	for (int i = 0; i <= size - len; i++)
	{
		if (src.substr(i, len) == sub)
			return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	int ret;
	char msg[30];
	int fd = open("request.txt", O_RDONLY);
	std::string str;
	
	int sock;
	struct sockaddr_in serv_addr;
	sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (-1 == connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))//sock에 write()한다고 생각하면 쉬울듯
	{
		printf("connect error\n");
		exit(1);
	}

	//
	std::cout << "start" << std::endl;
	while ((ret = read(fd, msg, 1)) != 0)
	{
		msg[ret] = 0;
		str += msg;
		if (ft_contain(str, "\n\n"))
		{
			write(sock, str.c_str(), str.size());
			std::cout << str << std::endl;
			write(sock, "\r\n\r\n", 4);
			str.clear();
			break;
		}
	}
	while ((ret = read(fd, msg, 1)) != 0)
	{
		msg[ret] = 0;
		str += msg;
	}
	std::cout << "file read over" << std::endl;
	write(sock, str.c_str(), str.size());
	std::cout << "wrtie" << std::endl;
	//shutdown(sock, SHUT_WR);
	int fd2 = open("response.txt", O_WRONLY);
	std::cout << "before read" << std::endl;
	while ((ret = read(sock, msg, 29)) != 0)//브라우저에서 shutdown 해줄예정
		write(fd2, msg, ret);
	std::cout << "after read" << std::endl;
	return 0;
}