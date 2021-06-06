#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__
#include <iostream>
#include <exception>
#include "form.hpp"
class Form;
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
		int	signForm(Form &src);
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


#endif
