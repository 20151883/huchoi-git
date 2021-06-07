#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

void pyramid(int start, int end, std::ofstream &test)
{
	for(int i=start; i<=end; i++)
	{
		for(int spaces=1; spaces<=end-i; spaces++) test<<" "; //spaces
		for(int j=1; j<=(2*i)-1; j++) test<<"*"; //pyramid
		test<<std::endl; //newline
	}
}

void base(int rows, std::ofstream &test)
{
	for(int i=0; i<=rows*0.3; i++)
	{
		for(int spaces=1; spaces<=rows*0.75; spaces++) test<<" "; //spaces
		for(int j=1; j<=rows*0.5; j++) test<<"*"; //stars
		test<<std::endl; //newline
	}
}

void make_tree(std::string filename)
{
	filename+=std::string("_shrubbery");
	std::ofstream test(filename.c_str(), std::ios::trunc);
	if (!test.is_open())
	{
		std::cout<<"open failed!!!"<<std::endl;
		return ;
	}
	int rows=15;
	pyramid(0,rows, test);
	pyramid(rows/2,rows, test);
	pyramid(rows/2,rows, test);
	base(rows, test);
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (getSign() == false)
	{
		std::cout<<"this form is not signed!! SIGN FIRST!!!!!"<<std::endl;
		throw SignSkipxception();
	}
	else if (getExecGrade() < executor.getGrade())
	{
		std::cout<<"executor's grade is lower than need grade "<<std::endl;
		throw GradeTooLowException();
	}
	make_tree(this->target);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->target;
}
