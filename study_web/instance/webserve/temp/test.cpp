#include "header.hpp"
#include <map>
#include <unistd.h>
#include <utility>
#include <string>
#include <fcntl.h>
#include <iostream>
#include <vector>

fd_set reads, cpyReads;

std::pair<int, std::string> ft_ex(int socket, std::string str)
{
    char buf[1000];
    int ret;
    static std::map<int, int> flag;
	for (std::map<int, int>::iterator i = flag.begin(); i != flag.end(); i++)
	{
		if (i->second == socket)
		{
			ret = read(i->second, buf, 999);
			buf[ret] = 0;
			FD_CLR(i->second, &reads);
			close(flag[socket]);
			int temp = i->first;
			flag.erase(i->first);
			return std::make_pair(temp, std::string(buf));
		}
	}
    if (flag.find(socket) == flag.end())
    {
		str.pop_back();
        int fd  = open(str.c_str(), O_RDONLY);
        std::cout << "fd  :" << fd << std::endl;
        flag[socket] = fd;  
        FD_SET(fd, &reads);
        return std::make_pair(fd, std::string(""));
    }
	else
		return std::make_pair(socket, std::string(""));
}

int main(int argc, char* argv[])
{
    int listenFD, connectFD;
	int opt;
    struct sockaddr_in listenSocket, connectSocket;
    struct timeval timeout;
	std::vector<int> files;
    // reads, cpyReads 생성
    // 이때 cpyReads는 while에서 reads의 복제를 위해 이용
    socklen_t addrSz; // address size를 구할 변수
    int fdMax, strLen, fdNum, i;
    char buf[BUFFER_SIZE];
    listenFD = socket(PF_INET, SOCK_STREAM, 0);
	setsockopt(listenFD, SOL_SOCKET, SO_REUSEADDR , &opt, sizeof(opt));

    memset(&listenSocket, 0, sizeof(listenSocket));
    listenSocket.sin_family = AF_INET;
    listenSocket.sin_addr.s_addr = htonl(INADDR_ANY);
    listenSocket.sin_port = htons(PORT);
    if (bind(listenFD, (struct sockaddr *) &listenSocket, sizeof(listenSocket)) == -1) {
        printf("Can not bind.\n");
        return -1;
    }
    if (listen(listenFD, LISTEN_QUEUE_SIZE) == -1) {
        printf("Listen fail.\n");
        return -1;
    }
    FD_ZERO(&reads); // 소켓 셋 초기화
    FD_SET(listenFD, &reads); //  listenFD 소켓 셋 1로 설정
    fdMax = listenFD; // 소켓 마지막 번호를 받아온다
    printf("소켓 마지막 번호 : %d\n", listenFD);
    while (1)
    {
        cpyReads = reads; // 복제
        int readBytes;
        char receiveBuffer[BUFFER_SIZE];
        timeout.tv_sec = 5;  // 5초
        timeout.tv_usec = 0;
        if ((fdNum = select(fdMax + 1, &cpyReads, 0, 0, &timeout)) == -1) // 타임아웃은 5초로 지정한다.
            break; // select 실패시
        for (i = 0; i < fdMax + 1; i++)
        {
            if (FD_ISSET(i, &cpyReads)) // fd가 켜져있다면
            {
                if (i == listenFD) // 그때 i가 FD와 같다면
                {
                    addrSz = sizeof(connectSocket);
                    connectFD = accept(listenFD, (struct sockaddr*)&connectSocket, &addrSz);
                    FD_SET(connectFD, &reads); // reads 소켓 셋에 connectFD를 부분을 1로 바꾼다
                    if (fdMax < connectFD)
                        fdMax = connectFD;
                    printf("connected client : %d\n", connectFD);
                }
                else
                {
					bool c = true;
					for (std::vector<int>::iterator iter = files.begin(); iter != files.end(); iter++)
					{
						if (*iter == i)
							c = false;
					}
					if (c == true)
                    {
						strLen = read(i, buf, BUFFER_SIZE);
                   		 buf[strLen] = 0;
						// close request
						if (strLen == 0)
						{
							FD_CLR(i, &reads); // 0으로 지운다
							close(i);
							printf("close client : %d\n", i);
						}
						else
						{
							std::string str = buf;
							std::pair<int, std::string> ret = ft_ex(i, str);
							fdMax++;
							if (ret.first > 0)
							{
								files.push_back(ret.first);
								continue;
							}
						}
					}
                    else
                    {
                        std::pair<int, std::string> ret = ft_ex(i, "");
						write(ret.first, ret.second.c_str(), ret.second.size());
                    }
                }
            }
        }
    }
    close(listenFD);
    return 0;
}