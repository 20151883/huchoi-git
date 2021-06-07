#include <iostream>

#include <cctype>
using namespace std;
static void trimize(std::string &str)
{
	std::string::iterator i = str.begin();
	while (i != str.end())
	{
		if (isspace(*i))
		{
			cout<<"erase the space"<<endl;
			str.erase(i);
		}
		else if ('A' <= *i && *i <= 'Z')
		{
			*i += 'a' - 'A';
		}
		i++;
	}
}
void makeForm(std::string type, std::string tartget)
{//1. 모두 소문자로 바꾸고 탭이나 공백 모두 제거하기
	std::string robot = std::string("RobotomyRequestForm");
	std::string presi = std::string("PresidentialPardonForm");
	std::string tree = std::string("ShrubberyCreationForm");
	trimize(robot);
	cout<<robot<<endl;
}

int main(void)
{
	makeForm("test", "test");
	return (0);
}
