#ifndef __SYN__
#define __SYN__
#include "ISpaceMarine.hpp"
#include "ISquad.hpp"
#include <iostream>

class Squad: public ISquad//사실상 이 squad가 객체 핸들러
{
	private:
		int count;
		ISpaceMarine **arr;
	public:
		Squad() :count(0), arr(NULL)
		{}
		~Squad()
		{
			int i = 0;
			while (i < count)
			{
				delete arr[i];
				i++;
			}
		}
		virtual int getCount() const
		{
			return this->count;
		}
		virtual ISpaceMarine* getUnit(int idx) const
		{
			if (count - 1 < idx)
				return NULL;
			return arr[idx];
		}
		virtual int push(ISpaceMarine*src)
		{
			(this->count)++;
			ISpaceMarine **new_arr = new ISpaceMarine*[this->count];
			int i;
			for(i = 0;i < this->count - 1;i++)
				new_arr[i] = arr[i];
			if (this->arr)
				delete this->arr;
			new_arr[i] = src;
			this->arr = new_arr;
			return this->count;
		}
};

class TacticalMarine :public ISpaceMarine//사실상 무연산 클래스
{
	private:

	public:
		TacticalMarine()
		{
			std::cout<<"Tactical Marine ready for battle!"<<std::endl;
		}
		virtual ~TacticalMarine()
		{
			std::cout<< "Aaargh..."<<std::endl;
		}
		virtual ISpaceMarine* clone() const
		{
			ISpaceMarine *ret = new TacticalMarine(*this);
			return ret;
		}
		virtual void battleCry() const
		{
			std::cout<<"For the holy PLOT!"<<std::endl;
		}
		virtual void rangedAttack() const
		{
			std::cout<< "* attacks with a bolter *"<<std::endl;
		}
		virtual void meleeAttack() const
		{
			std::cout<< "* attacks with a chainsword *"<<std::endl;
		}
};

class AssaultTerminator :public ISpaceMarine//사실상 무연산 클래스
{
	private:

	public:
		AssaultTerminator()
		{
			std::cout<< "* teleports from space *"<<std::endl;
		}
		virtual ~AssaultTerminator()
		{
			std::cout<< "I’ll be back..."<<std::endl;
		}
		virtual ISpaceMarine* clone() const
		{
			ISpaceMarine *ret = new AssaultTerminator(*this);
			return ret;
		}
		virtual void battleCry() const
		{
			std::cout<< "This code is unclean. PURIFY IT!"<<std::endl;
		}
		virtual void rangedAttack() const
		{
			std::cout<< "* does nothing *"<<std::endl;
		}
		virtual void meleeAttack() const
		{
			std::cout<<  "* attacks with chainfists *"<<std::endl;
		}
};
#endif
