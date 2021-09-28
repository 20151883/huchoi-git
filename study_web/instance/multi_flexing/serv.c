#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF 100

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in clnt_addr, serv_addr;
	int str_len;
	char str[BUF];
	//
	
	fd_set set, temp;
	FD_ZERO(&set);
	int max_fd;
	int sel_ret;
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	struct timeval timeout;
	
	//

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if (-1 == (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))))
	{
		printf("bind error\n");
		exit(1);
	}
	if (-1 == listen(serv_sock, 10))
	{
		printf("listen error\n");
		exit(1);
	}

	//
	FD_SET(serv_sock, &set);
	max_fd = serv_sock;
	while (1)
	{
		timeout.tv_sec=5;
		timeout.tv_usec=5000;
		temp = set;
		if (-1 == (sel_ret = select(max_fd + 1, &temp, NULL, NULL, &timeout)))
		{
			printf("select error\n");
			break;
		}
		if (sel_ret == 0)
		{
			printf("time out\n");
			continue;
		}
		else
		{
			for (int i = 0; i < max_fd + 1; i++)
			{
				if (FD_ISSET(i, &temp))
				{
					if (i == serv_sock)
					{
						clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
						FD_SET(clnt_sock, &set);
						if (clnt_sock > max_fd)
							max_fd = clnt_sock;
						printf("connected client: %d \n", clnt_sock);
					}
					else
					{
						str_len = read(i, str, BUF);
						if (str_len == 0)
						{
							close(i);
							FD_CLR(i, &set);
							printf("close clnt :  %d\n", i);
							//if (max_fd == i)
						}
						else
						{
							//str[str_len] = 0; <- 필요 없는 코드
							write(i, str, str_len);
						}
					}
				}
			}
		}
	}
}