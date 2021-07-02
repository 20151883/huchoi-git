#include "book.hpp"

int main(void)
{
    book var;
    std::string cmd;

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
			var.print_one(std::atoi(cmd.c_str()));
        }
		else if (!cmd.compare(0, 5, "EXIT"))
			exit(0);
		else
			std::cout<<"error input"<<std::endl;
    }
}
