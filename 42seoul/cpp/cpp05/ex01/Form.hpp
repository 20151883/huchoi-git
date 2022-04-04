#ifndef FORM_HPP
#define FORM_HPP

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string name;
		int sign_bound;
		int exec_bound;
		bool sign;
		Form();
	public:
		Form(const char *name, int sign_bound, int exec_bound);
		Form(const Form &src);
		const Form & operator=(const Form &src);
		~Form();
		void 			beSigned(Bureaucrat &src);
		std::string 	getName() const;
		bool 			getSign() const;
		int 			getSignGrade() const;
		int 			getExecGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;
		};
};
std::ostream &operator<<(std::ostream &ost, const Form &src);

#endif
