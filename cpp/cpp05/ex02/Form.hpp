#ifndef __FORM__
#define __FORM__

class Bureaucrat;

#include "Bureaucrat.hpp"

class Form//순수가상함수가 있으면 그게 abstract class-> 인스턴스화 될수가 없어서!
{
	private:
		std::string 	name;
		int 			sign_bound;
		int 			exec_bound;
		bool 			sign;
		std::string		target;
		Form();

	public:
		Form(const char *name, int sign_bound, int exec_bound, std::string target);
		virtual ~Form();
		Form(const Form &src);
		const Form & operator=(const Form &src);

		void 				beSigned(Bureaucrat &src);
		virtual void 		execute(Bureaucrat const & executor) const = 0;
		void 				check_boundary(Bureaucrat const &src) const;
		const std::string 	&getName() const;
		bool 				getSign() const;
		int 				getSignGrade() const;
		int 				getExecGrade() const;
		std::string			getTarget() const;
		void				setName(std::string);
		void				setSign(bool);
		void				setSignGrade(int);
		void				setExecGrade(int);
		void				setTarget(std::string);
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
};

std::ostream &operator<<(std::ostream &ost, Form &src);

#endif
