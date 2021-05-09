#include <iostream>
#include <cstring>
#include <cstdlib>
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
    void    right_assign(std::string &buf) const;
	void	print() const;
};

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