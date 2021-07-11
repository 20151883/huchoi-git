#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class Form
{
	protected:
		std::string name;
		 int sign_bound;
		 int exec_bound;
		bool sign;
		Form();
	public:
		Form(const char *name, int sign_bound, int exec_bound);
		virtual ~Form();
		Form(const Form &src);
		void beSigned(Bureaucrat &src);
		const Form & operator=(const Form &src);
		virtual void execute(Bureaucrat const & executor) const = 0;
		virtual Form *clone(std::string target) = 0;
		void check_boundary(Bureaucrat const &src) const;
		std::string getName() const;
		bool getSign() const;
		int getSignGrade() const;
		int getExecGrade() const;
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const noexcept;//오버라이딩
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const noexcept;//오버라이딩
		};
};

std::ostream &operator<<(std::ostream &ost, Form &src);

#endif
