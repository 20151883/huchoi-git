#include <iostream>
#include <string>
#include <unistd.h>
#include <map>

std::string ft_strtok(const std::string &src, std::string deli)
{
	static int end = 0;
	const int _size = src.size();
	int start = end;
	std::string token;//return value
	
	if (end == std::string::npos)
	{
		end = 0;
		return deli;
	}
	start = src.find_first_not_of(deli, start);
	end = src.find_first_of(deli, start);

	if (end == std::string::npos)
		token = src.substr(start, _size - start);
	else
		token = src.substr(start, (end-1) -  start + 1);
	return token;
	
}

std::string get_next_line(const std::string &src) // 사용법이 조금 복잡할수도 있음...(static 지역변수 사용할때의 패턴이라고 생각하자)
{
	static int end = 0;
	const int _size = src.size();
	int start = ((end == 0) ? 0 : end + 1);
	std::string ret;

	if (end == std::string::npos)
	{
		end = 0;//신규 텍스트 파일에 대해 gnl호출하려면 이 코드가 필수적
		ret = "\n\n";
		return ret;
	}
	end = src.find_first_of("\n", start);
	if (end == std::string::npos)//last line
		ret = src.substr(start, _size - start);
	else
		ret = src.substr(start, (end-1) -  start + 1);//개행문자 빼고 substr
	return ret;
}

void parse_request(const std::string &src)
{
	std::string ret = get_next_line(src);
	std::map<std::string, std::string> map;

	std::string method = ft_strtok(ret, " \v\r\t");
	std::string path = ft_strtok(ret, " \v\r\t");
	std::string http = ft_strtok(ret, " \v\r\t");
	std::string version = ft_strtok(ret, " \v\r\t");
	ft_strtok(ret, " \v\r\t");//필수적임

	while ("\n\n" != (ret = get_next_line(src)))
	{
		map.insert(std::make_pair(ft_strtok(ret, " \v\r\t:"), ft_strtok(ret, " \v\r\t:")));//key = header field , value = something...
		ft_strtok(ret, " \v\r\t:");//필수적임
	}
	std::cout << method << std::endl;
	std::cout << path << std::endl;
	std::cout << http << std::endl;
	std::cout << version << std::endl;
	
	for (std::map<std::string, std::string>::iterator i = map.begin(); i != map.end(); i++)
		std::cout << i->first<< "    " << i->second << std::endl;
	
	/*
	std::map<std::string, std::string>::iterator t = map.end();
	t--;
	while ((ret = ft_strtok(t->second, " \v\r\t,")) != " \v\r\t,")
		std::cout << ret << std::endl;
	*/
}

int main(void)
{
	/*
	std::cout << "gnl test code 입니다" << std::endl;
	std::string test("this \n is new test \n \n\n\n last");
	std::string test2("this \n is new test \n \n\n\n last\n\n");
	std::string ret;
	while ("\n\n" != (ret = get_next_line(test)))
	{
		std::cout << ret << std::endl;
	}
	while ("\n\n" != (ret = get_next_line(test2)))
	{
		std::cout << ret << std::endl;
	}
	std::cout << "gnl test code 입니다 끝!!!!" << std::endl;
	*/
	std::cout << "parse_request 함수 테스트 입니다" << std::endl;
	std::string test3 = "get /index.html HTTP 1.1\nAccept-Language : ko-KR,ko;q=0.8,en-US;q=0.5,en;q=0.3";
	parse_request(test3);
	std::cout << "parse_request 함수 테스트 입니다 끝!!!!" << std::endl;
	return 0;
}