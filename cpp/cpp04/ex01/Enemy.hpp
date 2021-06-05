class Enemy
{
	protected:
		int hp;
		std::string type;
	public:
		Enemy(int hp, std::string const & type): hp(hp), type(type)
		{}
		~Enemy()
		{}
		Enemy(Enemy &src)
		{
			this->hp = src.hp;
			this->type = src.type;
		}
		Enemy &operator=(Enemy &src)
		{
			this->hp = src.hp;
			this->type = src.type;
		}
		std::string getType() const
		{
			return this->type;
		}
		int getHP() const
		{
			return this->hp;
		}
		virtual void takeDamage(int);
};

class SuperMutant :public Enemy
{
	private:
		std::string sound;
		int flag;
	public:
		SuperMutant() :Enemy(170,"Super Mutant"), flag(0)
		{
			std::cout<<"Gaaah. Me want smash heads!"<<std::endl;
			this->sound = "Aaargh...";
		}
		~SuperMutant()
		{}
		SuperMutant(SuperMutant &src)//같은 클래스의 객체에 대해서는 굳이 get, set을 안쓰는게 코드상 깔끔해보임.
		{
			this->hp = src.hp;
			this->type = src.type;
			this->sound = src.sound;
			this->flag = src.flag;
		}
		SuperMutant &operator=(SuperMutant &src)
		{
			this->hp = src.hp;
			this->type = src.type;
			this->sound = src.sound;
			this->flag = src.flag;
		}
		virtual void takeDamage(int num)
		{
			//dmg = this->hp > 3 ? num - 3 : this->hp;
			dmg = num > 3 ? num - 3 : 0;
			this->hp -= dmg;
			if (this->hp <= 0)
			{
				if (this->flag == 0)
					std::cout<this->sound<<std::endl;
				flag = 1;
				this->hp = 0;
			}
		}
};

class RadScorpion :public Enemy
{
	private:
		std::string sound;
		int flag;
	public:
		SuperMutant() :Enemy(80,"RadScorpion"), flag(0)
		{
			std::cout<<"* click click click *"<<std::endl;
			this->sound = "* SPROTCH *";
		}
		~SuperMutant()
		{}
		SuperMutant(SuperMutant &src)//같은 클래스의 객체에 대해서는 굳이 get, set을 안쓰는게 코드상 깔끔해보임.
		{
			this->hp = src.hp;
			this->type = src.type;
			this->sound = src.sound;
			this->flag = src.flag;
		}
		SuperMutant &operator=(SuperMutant &src)
		{
			this->hp = src.hp;
			this->type = src.type;
			this->sound = src.sound;
			this->flag = src.flag;
		}
		virtual void takeDamage(int num)
		{
			//dmg = this->hp > 3 ? num - 3 : this->hp;
			dmg = num
			this->hp -= dmg;
			if (this->hp <= 0)
			{
				if (this->flag == 0)
					std::cout<this->sound<<std::endl;
				flag = 1;
				this->hp = 0;
			}
		}
};
