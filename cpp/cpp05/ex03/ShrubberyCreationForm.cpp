#include "ShrubberyCreationForm.hpp"

static void pyramid(int start, int end, std::ofstream &test)
{
	for(int i=start; i<=end; i++)
	{
		for(int spaces=1; spaces<=end-i; spaces++) test<<" "; //spaces
		for(int j=1; j<=(2*i)-1; j++) test<<"*"; //pyramid
		test<<std::endl; //newline
	}
}

static void base(int rows, std::ofstream &test)
{
	for(int i=0; i<=rows*0.3; i++)
	{
		for(int spaces=1; spaces<=rows*0.75; spaces++) test<<" "; //spaces
		for(int j=1; j<=rows*0.5; j++) test<<"*"; //stars
		test<<std::endl; //newline
	}
}

static void make_tree(std::string filename)
{
	filename += std::string("_shrubbery");
	std::ofstream test(filename.c_str(), std::ios::trunc);
	if (!test.is_open())
	{
		std::cout<<"opening new file is failed!!!"<<std::endl;
		return ;
	}
	int rows = 15;
	pyramid(0,rows, test);
	pyramid(rows/2,rows, test);
	pyramid(rows/2,rows, test);
	base(rows, test);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	check_boundary(executor);
	make_tree(this->target);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const char *target) :Form("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm():Form("ShrubberyCreationForm", 145, 137), target("noName")
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):Form("ShrubberyCreationForm", 145, 137)
{
	this->target = src.target;
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	this->name = src.getName();
	this->sign_bound = src.getSignGrade();
	this->exec_bound = src.getExecGrade();
	this->sign = src.getSign();

	this->target = src.getTarget();
	return *this;
}

Form *ShrubberyCreationForm::clone(std::string _target)
{
	Form *ret = new ShrubberyCreationForm(_target.c_str());
	return ret;
}