#include "Karen.hpp"

const Karen::func_list Karen::arr[] =
{
	{"DEBUG", &Karen::debug},
	{"INFO", &Karen::info},
	{"WARNING", &Karen::warning},
	{"ERROR", &Karen::error}
};

void Karen::debug( void )
{
	//void (Karen::*info)();
	//info = &Karen::info;
	std::cout<< "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"<<std::endl;
	//(this->*info)();
}
void Karen::info( void)
{
	//void (Karen::*warn)();
	//warn = &Karen::warning;
	std::cout<< "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"<<std::endl;
	//(this->*warn)();
}
void Karen::warning( void)
{
	//void (Karen::*err)();
	//err = &Karen::error;
	std::cout<< "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."<<std::endl;
	//(this->*err)();
}
void Karen::error( void)
{
	std::cout<< "This is unacceptable, I want to speak to the manager now."<<std::endl;
}

void Karen::complain( std::string level)
{
	int flag = 0;
	for (int i = 0; i < 4;i++)
	{
		if (std::string(arr[i].lv) == level)
		{
			flag = 1;
			(this->*arr[i].func)();
			return ;
		}
	}
	if (flag == 0)
		std::cout<<"no matching LEVEL"<<std::endl;
}

/*void complain(level)
{
	Karen::level
}*/
