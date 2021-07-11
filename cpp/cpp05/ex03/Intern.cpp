#include "Intern.hpp"


const Intern::Map Intern::arr[] = {
	{"shrubberycreationform", new ShrubberyCreationForm("no target")},
	{"robotomyrequestform", new RobotomyRequestForm("no target")},
	{"presidentialpardonform", new PresidentialPardonForm("no target")}
};

Intern::~Intern()
{
	for (int i=0;i < 3;i++)
		delete arr[i].form;
}

Intern::Intern()
{}

Intern::Intern(Intern&src)
{
	(void)src;
}

Intern &Intern::operator=(Intern &src)
{
	(void)src;
	return (*this);
}



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
Form *Intern::makeForm(std::string _type, std::string _target)
{//1. 모두 소문자로 바꾸고 탭이나 공백 모두 제거하기
	trimize(_type);
	Form *ret = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (arr[i].type == _type || arr[i].type == _type + std::string("form"))
			ret = arr[i].form->clone(_target.c_str());
	}
	return ret;
}
