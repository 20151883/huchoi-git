#ifndef SORCERER_HPP
#define SORCERER_HPP

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
		void announce();
		void polymorph(Victim const &victim) const;
		const std::string &getName() const;
		const std::string &getTitle() const;
		Sorcerer &operator=(const Sorcerer &src);
		virtual ~Sorcerer();
};

std::ostream& operator<<(std::ostream &ost, Sorcerer &src);

#endif
