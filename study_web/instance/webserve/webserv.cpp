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

#include "client.hpp"
#include "utils_for_parse.hpp"

#define BUF_SIZE 102410
#define SMALL_BUF 100

void error_handling(const char* message);

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_size;
	char buf[BUF_SIZE];
	pthread_t t_id;	
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	//

	fd_set read_set, read_temp;
	FD_ZERO(&read_set);
	int fd_max;
	int ret;
	std::string str;
	struct timeval timeout;

	//

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));
	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	if(listen(serv_sock, 20)==-1)
		error_handling("listen() error");

	//

	FD_SET(serv_sock, &read_set);
	fd_max = serv_sock;

	while(1)
	{
		timeout.tv_sec = 5;
		timeout.tv_usec = 5000;
		read_temp = read_set;
		ret = select(fd_max + 1, &read_temp, NULL, NULL, &timeout);// 여기서 fd_max + 1 <-> fd_max 
		if (ret < 0)
		{
			printf("some error detached");
			break;
		}
		else if (ret == 0)
		{
			printf("time out!\n");
			continue;
		}
		else
		{
			for (int i = 0; i < fd_max + 1; i++)
			{
				if (FD_ISSET(i, &read_temp))
				{
					if (i == serv_sock)
					{
						std::cout << "new clnt is connected" << std::endl;
						clnt_adr_size=sizeof(clnt_adr);
						clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_adr, &clnt_adr_size);
						FD_SET(clnt_sock, &read_set);
						if (fd_max < clnt_sock)
							fd_max = clnt_sock;
					}
					else //read message
					{
						//

						str.clear();
						client obj(i);
						str = obj.get_response();
						write(i, str.c_str(), str.size());
						str.clear();
						FD_CLR(i, &read_set);
						shutdown(i, SHUT_WR);
						
						//
						
						/*
						while (1)
						{	
							ret = read(i, buf, BUF_SIZE - 1);
							buf[ret] = 0;
							str += std::string(buf);
							if (ft_contain(str, "\r\n\r\n"))// 헤더의 끝
							{
								client obj(str);
								str = obj.get_response();
								write(i, str.c_str(), str.size());
								str.clear();
								FD_CLR(i, &read_set);
								shutdown(i, SHUT_WR);
								break;
							}
							else
							{
								std::cout << ret << std::endl;
							}
						}
						*/
					}
				}
			}
		}
	}
	close(serv_sock);
	return 0;
}

void error_handling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
