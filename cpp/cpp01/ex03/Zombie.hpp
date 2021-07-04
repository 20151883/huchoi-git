#include <iostream>
class Zombie
{
	private:
		std::string type;
		std::string name;
	public:
		Zombie(std::string input_type, std::string input_name="non name");
		void announce(void);
		~Zombie();
};
