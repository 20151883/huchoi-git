#include <iostream>
#include <cctype>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "form.hpp"
static void trimize(std::string &str)
{
	std::string::iterator i = str.begin();
	while (i != str.end())
	{
		if (isspace(*i))
		{
			str.erase(i);
		}
		else if ('A' <= *i && *i <= 'Z')
		{
			*i += 'a' - 'A';
		}
		i++;
	}
}
Form *Intern::makeForm(std::string type, std::string tartget)
{//1. 모두 소문자로 바꾸고 탭이나 공백 모두 제거하기
	std::string robot = std::string("RobotomyRequest");
	std::string presi = std::string("PresidentialPardon");
	std::string tree = std::string("ShrubberyCreation");
	trimize(robot);
	trimize(presi);
	trimize(tree);
	trimize(type);
	Form *ret = NULL;
	if (type == robot)
	{
		ret = new RobotomyRequestForm(tartget.c_str());
	}
	else if (type == presi)
	{
		ret = new PresidentialPardonForm(tartget.c_str());
	}
	else if (type == tree)
	{
		ret = new ShrubberyCreationForm(tartget.c_str());
	}
	else
	{
		std::cout<<"no matched type of form"<<std::endl;
	}
	//std::cout<<"this is test\n"<<robot<<"\n"<<type<<std::endl;
	return ret;
}
