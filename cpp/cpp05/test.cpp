class Parent
{
	protected:
		int age;
		int leg;
	public:
		virtual announce()
		{
		}
		virtual void test(void)
		{}
}

class Human :Parent
{
	public:
		virtual announce()
		{
			std::cout<<"HUMAN"<<std::endl;
		}
		void test(void)
		{
			std::cout<<"test"<<std::endl;
		}
}

class Zombie:Parent
{
	public:
		virtual announce()
		{
			std::cout<<"ZOMbie"<<std::endl;
		}
}



void main(void)
{
	Parent *p1 = Human();
	Parent *p2 = Zombie();
	p1->announce();
	p1->test();
	p2->announce();
	return 0;
}
