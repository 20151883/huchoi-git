#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <exception>

class Form;

#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
		Bureaucrat();
	public:
		Bureaucrat(const char *name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		const Bureaucrat &operator=(const Bureaucrat &src);
		const std::string &getName() const;
		int getGrade() const;
		void increasegrade();
		void decreasegrade();
		void signForm(Form &src);
		void executeForm(Form const & src);
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;//오버라이딩
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;//오버라이딩
		};
};

std::ostream& operator<<(std::ostream &ost, Bureaucrat &src);

#endif
