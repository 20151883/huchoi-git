#include <iostream>
#include <cstring>
#include <cstdlib>
//정보은늑과 캡슐화를 달성한 클래스를 만드는 것이 목표.
class CRAPPY
{
	private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_address;
	std::string email_address;
	std::string phone_number;
	std::string birthday_date;
	std::string favorite_meal;
	std::string underwear_color_and_darkest_secret;

	public:
	void 	add();
	void	search(int count) const;
	void	print() const;
};
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
void    CRAPPY::search(int index) const
{
	int size;
	std::string buf;
	//buf.shrink_to_fit();
	//std::cout<<"test : "<<buf<<std::endl;
	buf.insert(0, 1, index + '0');
	size = buf.size();
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
	std::cout<<buf<<"|";

	buf = first_name;
	size = buf.size();
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
	std::cout<<buf<<"|";

	buf = last_name;
	size = buf.size();
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
	std::cout<<buf<<"|";

	buf = nickname;
	size = buf.size();
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
	std::cout<<buf<<"|";

	std::cout<<std::endl;
}

void    CRAPPY::print() const
{
    std::cout<<"\n*************************"<<std::endl;
	std::cout<<"the information is ..."<<std::endl;
	std::cout<<"*************************"<<std::endl;
	std::cout<<"first_name                         : ";
	std::cout<<first_name;
	std::cout<<std::endl;
	std::cout<<"last_name                          : ";
	std::cout<<last_name;
	std::cout<<std::endl;
	std::cout<<"nickname                           : ";
	std::cout<<nickname;
	std::cout<<std::endl;
	std::cout<<"login                              : ";
	std::cout<<login;
	std::cout<<std::endl;
	std::cout<<"postal_address                     : ";
	std::cout<<postal_address;
	std::cout<<std::endl;
	std::cout<<"email_address                      : ";
	std::cout<<email_address;
	std::cout<<std::endl;
	std::cout<<"phone_number                       : ";
	std::cout<<phone_number;
	std::cout<<std::endl;
	std::cout<<"birthday_date                      : ";
	std::cout<<birthday_date;
	std::cout<<std::endl;
	std::cout<<"favorite_meal                      : ";
	std::cout<<favorite_meal;
	std::cout<<std::endl;
	std::cout<<"underwear_color_and_darkest_secret : ";
	std::cout<<underwear_color_and_darkest_secret<<std::endl;
}
//객체 핸들러.
class book{
    private:
        int num_of_men;
        CRAPPY mans[8];
    public:
        book (void) :num_of_men(0)
        {};
        void    add_one();
        void    search_all() const;
        void    print_one(int index) const;
};

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
	
int main(void)
{
    book var;
    std::string cmd;
    int index;
    while (1)
    {
        std::cout<<"INPUT YOUR CMD : "<<std::endl;
        std::getline(std::cin, cmd);
        if (!cmd.compare(0, 4, "ADD"))
            var.add_one();
        else if (!cmd.compare(0, 7, "SEARCH"))
        {
            var.search_all();
            std::cout<<"select your index : ";
            std::getline(std::cin, cmd);
			char *str = new char(cmd.size() + 1);
			std::strcpy(str, cmd.c_str());
			var.print_one(std::atoi(str));
			free(str);
        }
		else if (!cmd.compare(0, 5, "EXIT"))
			exit(0);
		else
			std::cout<<"error input"<<std::endl;
    }
}