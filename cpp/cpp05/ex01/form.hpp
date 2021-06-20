#ifndef __FORM__
#define __FORM__
class Form;
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool sign;
		const int sign_bound;
		const int exec_bound;
	public:
		Form(const char *name, int sign_bound, int exec_bound) :name(name), sign_bound(sign_bound), exec_bound(exec_bound), sign(false)
		{
			if (sign_bound < 1)
				throw GradeTooHighException();
			if (sign_bound >150)
				throw GradeTooLowException();
			if (exec_bound < 1)
				throw GradeTooHighException();
			if (exec_bound >150)
				throw GradeTooLowException();
		}
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT//오버라이딩
    			{
        			return "TOO HIGH  BOUND";
    			}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const _NOEXCEPT//오버라이딩
    			{
        			return "TOO LOW  BOUND";
    			}
		};
		void beSigned(Bureaucrat &src);
		std::string getName()
		{
			return this->name;
		}
		bool getSign()
		{
			return this->sign;
		}
		int getSignGrade()
		{
			return this->sign_bound;
		}
		int getExecGrade()
		{
			return this->exec_bound;
		}
};
std::ostream &operator<<(std::ostream &ost, Form &src);

#endif
