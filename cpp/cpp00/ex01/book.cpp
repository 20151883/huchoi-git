#include "book.hpp"

void    CRAPPY::add()
{
    std::cout<<"give me first_name : ";
	std::getline(std::cin, first_name);
	std::cout<<std::endl;
	std::cout<<"give me last_name : ";
	std::getline(std::cin, last_name);
	std::cout<<std::endl;
	std::cout<<"give me nickname : ";
	std::getline(std::cin, nickname);
	std::cout<<std::endl;
	std::cout<<"give me login : ";
	std::getline(std::cin, login);
	std::cout<<std::endl;
	std::cout<<"give me postal_address : ";
	std::getline(std::cin, postal_address);
	std::cout<<std::endl;
	std::cout<<"give me email_address : ";
	std::getline(std::cin, email_address);
	std::cout<<std::endl;
	std::cout<<"give me phone_number : ";
	std::getline(std::cin, phone_number);
	std::cout<<std::endl;
	std::cout<<"give me birthday_date : ";
	std::getline(std::cin, birthday_date);
	std::cout<<std::endl;
	std::cout<<"give me favorite_meal : ";
	std::getline(std::cin, favorite_meal);
	std::cout<<std::endl;
	std::cout<<"give me underwear_color_and_darkest_secret : ";
	std::getline(std::cin, underwear_color_and_darkest_secret);
	std::cout<<"\n"<<"***************************************************"<<std::endl;
	std::cout<<"all information is succesfully stored!!!!";
	std::cout<<"\n"<<"***************************************************"<<std::endl;
}

void    CRAPPY::right_assign(std::string &buf) const
{
	int size = buf.size();
	if (size <= 10)
	{
		while (size++ < 10)
			buf.insert(0, " ");
	}
	else
	{
		buf.resize(9);
		buf+=".";
	}
}

void    CRAPPY::search(int index) const
{
	std::string buf;
	int start = 0;
	buf.insert(start, 1, index + '0');
	right_assign(buf);
	std::cout<<buf<<"|";

	buf = first_name;
	right_assign(buf);
	std::cout<<buf<<"|";

	buf = last_name;
	right_assign(buf);
	std::cout<<buf<<"|";

	buf = nickname;
	right_assign(buf);
	std::cout<<buf<<"|";

	std::cout<<std::endl;
}

void    CRAPPY::print() const
{
    std::cout<<"\n*************************"<<std::endl;
	std::cout<<"the information is ..."<<std::endl;
	std::cout<<"*************************"<<std::endl;
	std::cout<<"first_name                         : ";
	std::cout<<first_name<<std::endl;
	std::cout<<"last_name                          : ";
	std::cout<<last_name<<std::endl;
	std::cout<<"nickname                           : ";
	std::cout<<nickname<<std::endl;
	std::cout<<"login                              : ";
	std::cout<<login<<std::endl;
	std::cout<<"postal_address                     : ";
	std::cout<<postal_address<<std::endl;
	std::cout<<"email_address                      : ";
	std::cout<<email_address<<std::endl;
	std::cout<<"phone_number                       : ";
	std::cout<<phone_number<<std::endl;
	std::cout<<"birthday_date                      : ";
	std::cout<<birthday_date<<std::endl;
	std::cout<<"favorite_meal                      : ";
	std::cout<<favorite_meal<<std::endl;
	std::cout<<"underwear_color_and_darkest_secret : ";
	std::cout<<underwear_color_and_darkest_secret<<"\n"<<std::endl;
}

void    book::add_one()
{
	if (num_of_men >= 8)
		std::cout<<"memory is full"<<std::endl;
	else
		mans[num_of_men++].add();
}

 void    book::search_all() const
{
	int idx = -1;
	while (++idx < num_of_men)
	mans[idx].search(idx);
}

void    book::print_one(int index) const
{
	if (0 <= index && index < num_of_men)
		mans[index].print();
	else
		std::cout<<"your index is not valid"<<std::endl;
}
