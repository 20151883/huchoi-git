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
		int					grade;
	public:
		Bureaucrat(const char *name, int grade) :name(name)
		{
			if (grade < 1)
				throw GradeTooHighException();
			else if (grade > 150)
				throw GradeTooLowException();
			this->grade = grade;
		}
		void	signForm(Form &src);
		std::string getName();
		int getGrade();
		void increasegrade();
		void decreasegrade();


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
std::ostream& operator<<(std::ostream &ost, Bureaucrat &src);

#endif
