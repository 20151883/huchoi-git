#include <iostream>
#include <form.h>
class Form;
class Intern
{
	private:

	public:
		//Intern()
		//{}
		//Intern(Intern&src)
		//{}
		//Intern &operator=()
		//{}
		~Intern()
		{}
		Form *makeForm(std::string type, std::string tartget);
};
