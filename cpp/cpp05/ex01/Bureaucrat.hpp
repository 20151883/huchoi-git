#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__
#include <iostream>
#include <exception>
#include "form.hpp"


class Bureaucrat
{
	private:
		const std::string	name;
		int					range;
	public:
		Bureaucrat(const char *name, int range) :name(name)
		{
			if (range < 1)
				throw GradeTooLowException();
			else if (range > 150)
				throw GradeTooHighException();
			this->range = range;
		}
		int	signForm(Form &src)
		{
			if (this->range <= src.getSignGrade() && !src.getSign())
			{
				std::cout<<this->name<<" signs "<< src.getName() <<std::endl;
				return 1;
			}
			else if (this->range > src.getSignGrade() && src.getSign())
				std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"low grade and this form already signed!!!"<<std::endl;
			else if (this->range > src.getSignGrade())
				std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"low grade"<<std::endl;
			else
				std::cout<<this->name<<" cannot sign "<<src.getName()<<" because "<<"form already signed"<<std::endl;
			return 0;
		}
		std::string getName()
		{
			return this->name;
		}
		int getGrade()
		{
			return this->range;
		}
		void increaseRange()
		{
			this->range -= 1;
			if (range < 1)
				throw GradeTooLowException();
			else if (range > 150)
				throw GradeTooHighException();
		}
		void decreaseRange()
		{
			this->range += 1;
			if (range < 1)
				throw GradeTooLowException();
			else if (range > 150)
				throw GradeTooHighException();
		}


		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT//오버라이딩
    			{
        			return "TOO LOW";
    			}
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT//오버라이딩
    			{
        			return "TOO HIGH";
    			}
		};
};

std::ostream& operator<<(std::ostream &ost, Bureaucrat &src)
{
	printf("<%s>, bureaucrat grade <%d>.", src.getName().c_str(), src.getGrade());
	return ost;
}
#endif
