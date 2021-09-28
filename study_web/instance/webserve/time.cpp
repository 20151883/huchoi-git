#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

// 현재시간을 string type으로 return하는 함수

const std::string currentDateTime() {
		time_t     now = time(0); //현재 시간을 time_t 타입으로 저장
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		if (tstruct.tm_hour >= 9)
		{
        	tstruct.tm_hour -= 9;
            tstruct.tm_mday -= 1;
        }
		else
		{
			tstruct.tm_hour += (24 - 9);
			tstruct.tm_mday -= 1;
		}
		strftime(buf, sizeof(buf), "%a, %d %b %Y %T GMT", &tstruct);
		return buf;
	}

int main() {
    std::cout << "지금 시간은:" << currentDateTime() << std::endl;
}
//Date: Thu, 17 Aug 2017 05:52:23 GMT