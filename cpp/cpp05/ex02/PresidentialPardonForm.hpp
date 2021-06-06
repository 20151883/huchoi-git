#include "form.hpp"
class Form;

class PresidentialPardonForm : public Form
{
	private:
		std::string target;
	public:
		PresidentialPardonForm(const char *target) :target(target) ,Form("PresidentialPardonForm", 25, 5), target(target)
		{}
};
