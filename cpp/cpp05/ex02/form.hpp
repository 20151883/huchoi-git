#ifndef __FORM__
#define __FORM__
class Form;
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		const int sign_bound;
		const int exec_bound;
		bool sign;
		Form();
	public:
		Form(const char *name, int sign_bound, int exec_bound);
		virtual ~Form();
		Form(Form &src);
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;//오버라이딩
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT;//오버라이딩
		};
		void beSigned(Bureaucrat &src);
		virtual void execute(Bureaucrat const & executor) const = 0;
		void check_boundary(Bureaucrat const &src) const;
		std::string getName() const;
		bool getSign();
		int getSignGrade();
		int getExecGrade();
};

std::ostream &operator<<(std::ostream &ost, Form &src);

#endif
