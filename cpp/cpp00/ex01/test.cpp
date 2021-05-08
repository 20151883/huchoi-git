#include <iostream>
#include <cstring>
#include <cstdlib>

class CRAPPY
{
	private:
	char first_name[100];
	char last_name[100];
	char nickname[100];
	char login[100];
	char postal_address[100];
	char email_address[100];
	char phone_number[100];
	char birthday_date[100];
	char favorite_meal[100];
	char underwear_color_and_darkest_secret[100];

	public:
	void 	fill_the_var();
	void	search_cmd(int count) const;
	void	print_information() const;
};

void		CRAPPY::fill_the_var()
{
	std::cout<<"give me first_name : ";
	std::cin>>first_name;
	std::cout<<std::endl;
	std::cout<<"give me last_name : ";
	std::cin>>last_name;
	std::cout<<std::endl;
	std::cout<<"give me nickname : ";
	std::cin>>nickname;
	std::cout<<std::endl;
	std::cout<<"give me login : ";
	std::cin>>login;
	std::cout<<std::endl;
	std::cout<<"give me postal_address : ";
	std::cin>>postal_address;
	std::cout<<std::endl;
	std::cout<<"give me email_address : ";
	std::cin>>email_address;
	std::cout<<std::endl;
	std::cout<<"give me phone_number : ";
	std::cin>>phone_number;
	std::cout<<std::endl;
	std::cout<<"give me birthday_date : ";
	std::cin>>birthday_date;
	std::cout<<std::endl;
	std::cout<<"give me favorite_meal : ";
	std::cin>>favorite_meal;
	std::cout<<std::endl;
	std::cout<<"give me underwear_color_and_darkest_secret : ";
	std::cin>>underwear_color_and_darkest_secret;
	std::cout<<"\n"<<"***************************************************"<<std::endl;
	std::cout<<"all information is succesfully stored!!!!";
	std::cout<<"\n"<<"***************************************************"<<std::endl;
}

void	CRAPPY::search_cmd(int count)
{
	char buf[11];
	memset(buf, ' ', 10);
	buf[10] = '\0';
	int size;
	int start;
	buf[9] = count + '0';
	std::cout<<"\n"<<buf;
	size = strlen(first_name);
	size = size<=10?size:10;
	start = 10 - size;
	strncpy(&buf[start], first_name, size);
	if (strlen(first_name) > 10)
		buf[9] = '.';
	std::cout<<"|"<<buf;

	memset(buf, ' ', 10);
	buf[10] = '\0';
	size = strlen(last_name);
	size = size<=10?size:10;
	start = 10 -size;
	strncpy(&buf[start], last_name, size);
	if (strlen(last_name) > 10)
		buf[9] = '.';
	std::cout<<"|"<<buf;

	memset(buf, ' ', 10);
	buf[10] = '\0';
	size = strlen(nickname);
	size = size<=10?size:10;
	start = 10 -size;
	strncpy(&buf[start], nickname, size);
	if (strlen(nickname) > 10)
		buf[9] = '.';
	std::cout<<"|"<<buf<<std::endl;
};

void	CRAPPY::print_information()
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

int main(void)
{
	char cmd[100];
	//std::string cmd;
	int index = 0;
	CRAPPY book[8];
	while (1)
	{
		std::cout<<"**************************"<<std::endl;
		std::cout<<"PUT YOUR COMMND :";
		std::cin>>cmd;//만약 사용자가 100글자보다 많은 글자를 입력하면...?
		std::getline(std::cin, cmd);
		std::cout<<"**************************"<<std::endl;
		if (!strcmp(cmd, "ADD"))
		{
			if (index >= 8)
			{
				std::cout<<"\n"<<"***************************************************"<<std::endl;
				std::cout<<"memory is full.... cannot add any information"<<std::endl;
				std::cout<<"***************************************************"<<std::endl;
			}
			else
			{
				book[index].fill_the_var();
				index++;
			}
		}
		else if (!strcmp(cmd, "SEARCH"))
		{
			int count = 0;
			if (index == 0)
			{
				std::cout<<"**********************"<<std::endl;
				std::cout<<"this is empty contact"<<std::endl;
				std::cout<<"**********************"<<std::endl;
				continue;
			}
			while (count < index)
			{
				book[count].search_cmd(count);
				count++;
			}
			std::cout<<"\ngive the index number : ";
			char idx_num[100];
			std::cin>>idx_num;//여기서 문자열 입력면 이상한 에러가 발생함. 이 부분 에러 어떻게 고쳐야하는지 잘 모르겠음.
			count = atoi(idx_num);
			if (count >= index || count < 0)
			{
				std::cout<<"**********************************************************"<<std::endl;
				std::cout<<"you got the wrong number....lastest added member is ..."<<(index - 1)<<std::endl;
				std::cout<<"**********************************************************"<<std::endl;
				count = index - 1;
			}
			book[count].print_information();
		}
		else if (!strcmp(cmd, "EXIT"))
		{
			return (0);
		}
		else
		{
			std::cout<<"\n"<<"***************************************************"<<std::endl;
			std::cout<<"your cmd must be \"ADD\" or \"SEARCH\" or \"EXIT\" "<<std::endl;
			std::cout<<"***************************************************"<<std::endl;
		}
		std::cout<<std::endl;
	}
}
