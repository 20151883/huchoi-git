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
		const std::string &getName() const;//get함수는 모두 const 붙이는거로 습관들이기
		const std::string &getTitle() const;
		const Sorcerer &operator=(const Sorcerer &src);
		virtual ~Sorcerer();//virtual 붙이는게 맞나..?
};

std::ostream& operator<<(std::ostream &ost, Sorcerer &src);

#endif
