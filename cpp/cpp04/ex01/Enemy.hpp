class Enemy
{
	protected:
		int hp;
		std::string type;
		int flag;
	public:
		Enemy(int hp, std::string const & type): hp(hp), type(type), flag(0)
		{}
		virtual ~Enemy()
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
			return *this;
		}
		std::string getType() const
		{
			return this->type;
		}
		int getHp() const
		{
			return this->hp;
		}
		void setFlag(int num)
		{
			this->flag = num;
		}
		int getFlag()
		{
			return this->flag;
		}
		virtual void takeDamage(int) = 0;
};

class SuperMutant :public Enemy
{
	private:
		std::string sound;
	public:
		SuperMutant() :Enemy(170,"Super Mutant")
		{
			std::cout<<"Gaaah. Me want smash heads!"<<std::endl;
			this->sound = "Aaargh...";
		}
		virtual ~SuperMutant()
		{}
		SuperMutant(SuperMutant &src):Enemy(src.getHp(), src.getType())
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
			return *this;
		}
		virtual void takeDamage(int num)
		{
			int dmg = num > 3 ? num - 3 : 0;
			this->hp -= dmg;
			if (this->hp <= 0)
			{
				if (this->flag == 0)
					std::cout<<this->sound<<std::endl;
				setFlag(1);
				this->hp = 0;
			}
		}
		std::string getSound()
		{
			return this->sound;
		}
};

class RadScorpion :public Enemy
{
	private:
		std::string sound;
	public:
		RadScorpion() :Enemy(80,"RadScorpion")
		{
			std::cout<<"* click click click *"<<std::endl;
			this->sound = "* SPROTCH *";
		}
		virtual ~RadScorpion()
		{}
		RadScorpion(RadScorpion &src) :Enemy(src.getHp(), src.getType())
		{
			this->hp = src.hp;
			this->type = src.type;
			this->sound = src.sound;
			this->flag = src.flag;
		}
		RadScorpion &operator=(RadScorpion &src)
		{
			this->hp = src.hp;
			this->type = src.type;
			this->sound = src.sound;
			this->flag = src.flag;
			return *this;
		}
		virtual void takeDamage(int num)
		{
			//dmg = this->hp > 3 ? num - 3 : this->hp;
			int dmg = num;
			this->hp -= dmg;
			if (this->hp <= 0)
			{
				if (this->flag == 0)
					std::cout<<this->sound<<std::endl;
				setFlag(1);
				this->hp = 0;
			}
		}
		std::string getSound()
		{
			return this->sound;
		}
};
