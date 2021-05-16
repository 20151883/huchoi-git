#include <iostream>
#include <cstring>

class FragTrap{
	private:
		unsigned int Hit_point;
		unsigned int Max_hit_points;
		unsigned int Energy_points;
		unsigned int Max_energy_points;
		unsigned int Level;
		std::string Name;
		//const char *Name;
		unsigned int Melee_attack_damage;
		unsigned int Ranged_attack_damage;
		unsigned int Armor_damage_reduction;
	public:
		FragTrap(const char *name): Name(name), Hit_point(100), Max_hit_points(100), Energy_points(100), Max_energy_points(100), Level(1), \
									Melee_attack_damage(30), Ranged_attack_damage(20), Armor_damage_reduction(5)
		{
			std::cout<<"the FragTrap("<<Name<< ") is appeared!!!!"<<std::endl;
		}
		~FragTrap()
		{
			std::cout<<"the FragTrap("<<Name<< ") is disappeared!!!!"<<std::endl;
			//delete []Name;
		}
		FragTrap &operator=(FragTrap &src)//원래는 멤버변수에 const키워드가 몇개 있었는데, 대입연산자 오버로딩 구현하면서 없엘수밖에 없었음.
		{//이 클래스의 경우 얕은 복사해도 별 문제가 안생기긴 하는데...
			Hit_point = src.Hit_point;
			Max_hit_points = src.Max_hit_points;
			Energy_points = src.Energy_points;
			Max_energy_points = src.Energy_points;
			Level = src.Level;
			Name = src.Name;
			Melee_attack_damage = src.Melee_attack_damage;
			Ranged_attack_damage = src.Ranged_attack_damage;
			Armor_damage_reduction = src.Armor_damage_reduction;
			return (*this);
		}
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};
