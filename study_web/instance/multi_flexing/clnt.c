#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *msg);

int main(int argc, char *argv[])
{
	int sock;
	struct sockaddr_in serv_addr;
	char msg[30];

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
	while (1)
	{
		printf("input some message: ");
		fgets(msg, 30, stdin);//scanf의 특징: white space 보이면 끊어버림
		if (strcmp(msg, "q\n") == 0)
			break;
		write(sock, msg, strlen(msg));
		int str_len = read(sock, msg, sizeof(msg));
		msg[str_len] = 0;
		printf("the message is %s\n", msg);
	}
	close(sock);
	return 0;
}