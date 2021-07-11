#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cctype>

class Intern
{
	private:
		
	public:
		typedef struct Map{
			std::string type;
			Form *form;
		}Map;
		static const Map arr[];
		Intern();
		Intern(Intern&src);
		Intern &operator=(Intern &src);
		~Intern();
		Form *makeForm(std::string type, std::string tartget);
};

#endif