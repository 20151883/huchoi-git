#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[])
{
	int _serv_sock, _clnt_sock;
	struct sockaddr_in _serv_addr;
	struct sockaddr_in _clnt_addr;
	int _clnt_addr_size;
	int _size;

	_serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	memset(&_serv_addr, 0, sizeof(_serv_addr));
	_serv_addr.sin_family = AF_INET;
	_serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	_serv_addr.sin_port = htons(atoi(argv[1]));

	if (-1 == (bind(_serv_sock, (struct sockaddr *)&_serv_sock, sizeof(_serv_sock))))
	{
		printf("bind error");
		exit(1);
	}
	listen(_serv_sock, 10);
	_clnt_addr_size = sizeof(_clnt_addr);
	_clnt_sock = connect(_serv_sock, &_clnt_addr, &_clnt_addr_size);
	//통신과정은 여기서 진행한다
	close(_clnt_sock);
	close(_serv_sock);
	return 0;
}