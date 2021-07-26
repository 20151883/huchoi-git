#ifndef VICTIM_HPP
#define VICTIM_HPP

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
		const std::string &getName (void) const;
		void setName (const std::string &test);
		const Victim &operator=(const Victim &src);
		virtual ~Victim();
};

std::ostream &operator<<(std::ostream &ost, Victim &src);
#endif
