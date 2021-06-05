#include <iostream>

//operator<< 함수 오버로드(템플릿으로 정의하면 편하겠지만 일단은 각 클래스별로 함수정의하기)

class Victim
{
	private:
		std::string name;
	public:
	Victim(const char *n) :name(n)
	{
		std::cout<<"Some random victim called "<<name<<" just appeared!"<<std::endl;
	}
	Victim(const Victim &src)
	{
		name = src.get_name();
	}
    virtual void	 getPolymorphed() const
	{
		std::cout << name <<" has been turned into a cute little sheep!" << std::endl;
	}
	std::string get_name (void) const
	{
		return this->name;
	}
	void set_name (std::string &test)
	{
		this->name = test;
	}
	Victim &operator=(Victim &src)
	{
		this->name = src.get_name();
		return *this;
	}
	//virtual Peon	&operator=(Peon &src) = 0;//순수가상함수
	~Victim()
	{
		std::cout<<"Victim "<< name <<" just died for no apparent reason!"<<std::endl;
	}
};

class Peon : public Victim
{
	private:

	public:
	Peon(const char *n) :Victim(n)
	{
		std::cout<<"Zog zog."<<std::endl;
	}
	Peon(const Peon &src) :Victim(src.get_name().c_str())
	{
		std::cout<<"Zog zog."<<std::endl;
	}
    virtual void	 getPolymorphed() const
	{
        std::cout << get_name() <<" has been turned into a pink pony!" << std::endl;
	}
	virtual Peon	&operator=(Peon &src)//차라리 Victim에서 멤버변수를 protected 로 두었으면 더 편했을수도...
	{
		std::string str = src.get_name();
		this->set_name(str);
		return *this;
	}
	virtual ~Peon()
	{
		std::cout<<"Bleuark..."<<std::endl;
	}
};

class Sorcerer{
    private:
        std::string name;
        std::string title;
    public:
        Sorcerer(const char *n, const char *t) :name(n), title(t)
        {
            std::cout<<name<<", "<<title<<", is born!"<<std::endl;
        }
        Sorcerer(const Sorcerer &src)//여기서 객체의 참조값을 받지않고 객체 자체를 받으면 얕은복사 문제가 생길수있음,.
        {
            this->name = src.name;
			this->title = src.title;
        }
        void announce() const
        {
             std::cout<<"I am"<<name<<", "<<title<<","<<", and I like ponies!"<<std::endl;
        }
		void polymorph(Victim const &victim) const
		{
			victim.getPolymorphed();
		}
		std::string get_name()
		{
			return name;
		}
		std::string get_title()
		{
			return title;
		}
		Sorcerer &operator=(Sorcerer &src)
		{
			this->name = src.get_name();
			this->title = src.get_title();
			return *this;
		}
        virtual ~Sorcerer()
        {
             std::cout<<name<<", "<<title<<", is dead. Consequences will never be the same!"<<std::endl;
        }
};

std::ostream &operator<<(std::ostream &ost, Victim &src)
{
	printf("I\'m %s and I like otters!\n", src.get_name().c_str());
	fflush(stdout);
	return ost;
}
std::ostream& operator<<(std::ostream &ost, Sorcerer &src)
{
	printf("I am %s, %s, and I like ponies!\n", src.get_name().c_str(), src.get_title().c_str());
	fflush(stdout);
	return ost;
}
