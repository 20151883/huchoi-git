#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		std::string	name;
		int					grade;
	public:
		Bureaucrat(const char *name, int grade);
		Bureaucrat(Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat &src);
		std::string getName();
		int getGrade();
		void increasegrade();
		void decreasegrade();
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
