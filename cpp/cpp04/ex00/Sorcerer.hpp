#ifndef __SORCERER__
#define __SORCERER__

#include <iostream>
#include "Victim.hpp"

class Sorcerer{
	private:
		std::string name;
		std::string title;
		Sorcerer(void);
	public:
		Sorcerer(const char *n, const char *t);
		Sorcerer(const Sorcerer &src);
		void announce() const;
		void polymorph(Victim const &victim) const;
		std::string getName();
		std::string getTitle();
		Sorcerer &operator=(Sorcerer &src);
		virtual ~Sorcerer();
};

std::ostream& operator<<(std::ostream &ost, Sorcerer &src);

#endif
