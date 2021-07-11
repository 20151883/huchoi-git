#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Form;

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
	private:
		std::string	name;
		int					grade;
		Bureaucrat();
	public:
		Bureaucrat(const char *name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		const Bureaucrat &operator=(const Bureaucrat &src);
		std::string getName() const;
		int getGrade() const;
		void increasegrade();
		void decreasegrade();
		void signForm(Form &src);
		void executeForm(Form const & src);
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const noexcept;//오버라이딩
		};
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const noexcept;//오버라이딩
		};
};

std::ostream& operator<<(std::ostream &ost, Bureaucrat &src);

#endif
