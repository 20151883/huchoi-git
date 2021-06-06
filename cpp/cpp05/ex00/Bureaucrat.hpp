#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat(const char *name, int grade) :name(name)
		{
			if (grade < 1)
				throw GradeTooLowException();
			else if (grade > 150)
				throw GradeTooHighException();
			this->grade = grade;
		}
		Bureaucrat(Bureaucrat &src)
		{

		}
		~Bureaucrat()
		{}
		Bureaucrat &operator=(Bureaucrat &src)
		{
			this->name = src.getName();
			this->grade = src.getGrade();
		}
		std::string getName()
		{
			return this->name;
		}
		int getGrade()
		{
			return this->grade;
		}
		void increasegrade()
		{
			this->grade -= 1;
			if (grade < 1)
				throw GradeTooLowException();
			else if (grade > 150)
				throw GradeTooHighException();
		}
		void decreasegrade()
		{
			this->grade += 1;
			if (grade < 1)
				throw GradeTooLowException();
			else if (grade > 150)
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

std::ostream& operator<<(std::ostream &ost, Bureaucrat &src)
{
	printf("<%s>, bureaucrat grade <%d>.", src.getName().c_str(), src.getGrade());
	return ost;
}
