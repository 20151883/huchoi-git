#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *msg); 

//socker->sock
//address->addr

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	int str_len;
	char msg[30];
	int i;
	if (argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);//프로토콜_인터넷, 소켓의 타입중 sock_stream <-> sock_dgram(이산적 변량?!)
	if (serv_sock == -1)
		exit (1);
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_addr.sin_port=htons(atoi(argv[1]));

	if (-1 == (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))))//소켓에 write()함수 호출한다고 생각하면 쉬울듯
	{
		printf("bind error\n");
		exit(1);
	}
	listen(serv_sock, 10);
	
	socklen_t clnt_addr_size = sizeof(clnt_addr);
	for (i = 0; i< 5; i++)
	{	
	
		if (-1 == (clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size)))
		{
			printf("error\n");
			exit(1);
		}
		printf("the %d st clnt: \n", i);
		//이번엔 구조체변수에 (serv_sock에 적혀있는 내용을) wirte()함수 호출한다고 생각하면 쉬울듯
		//str_len = read(clnt_sock, msg, sizeof(msg) - 1);
		while ((str_len = read(clnt_sock, msg, sizeof(msg) - 1)) != 0) //EOF가 날라올때까지 
		{
			//msg[str_len] = 0;
			write(clnt_sock, msg, str_len);
		}
		printf("reach\n");
		close(clnt_sock);
	}
	/*
	for (int i = 0; i <2; i++)
		clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);//이번엔 구조체변수에 (serv_sock에 적혀있는 내용을) wirte()함수 호출한다고 생각하면 쉬울듯
	*/
	close(clnt_sock);
	close(serv_sock);

	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}