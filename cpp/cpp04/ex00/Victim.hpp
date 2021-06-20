#ifndef __VICTIM__
#define __VICTIM__
#include <iostream>

class Victim
{
	protected:
		std::string name;
		Victim();
	public:
		Victim(const char *n);
		Victim(const Victim &src);
		virtual void	 getPolymorphed() const;
		std::string getName (void) const;
		void setName (std::string &test);
		Victim &operator=(Victim &src);
		~Victim();
};

std::ostream &operator<<(std::ostream &ost, Victim &src);
#endif
