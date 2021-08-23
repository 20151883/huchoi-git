#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::vector <T> >
	class stack
	{
		//private:
		//	Container c;
		protected:
			Container c;
		public://c++ referenece	 보다 cppreference 사이트가 더 자세하게 나와있는듯...
			
			//typedef
			typedef Container container_type;
			typedef typename Container::value_type value_type;
			typedef typename Container::size_type size_type;
			typedef typename Container::reference reference;
			typedef typename Container::const_reference const_reference;

			//member_function

			explicit stack (const container_type& ctnr = container_type()):c(ctnr) {}
			~stack() {}
			stack &operator=(const stack &other)
			{
				//c.~Container(); 여기서 이 구문이 필요가 없음. 잘 생각해보기.
				//'왜 필요하다고 생각했는지' 그게 더 중요할수도...? -> 대입연산을 함수호출로 보질 못하고 진짜 대입연산하는걸로 보고있었음...(중요한 대목인듯...!!)
				c = other.c;
				return *this;
			}

			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			bool empty() const{ return (c.empty()); }
			size_type size() const{ return c.size(); }
			
			void push (const value_type& val) { c.push_back(val); }
			void pop( ){ c.pop_back(); }
			

			private:

				template <class A, class B>
				friend bool operator== (const stack<A,B>& lhs, const stack<A,B>& rhs);
				template <class A, class B>
				friend bool operator!= (const stack<A,B>& lhs, const stack<A,B>& rhs);
				template <class A, class B>
				friend bool operator<  (const stack<A,B>& lhs, const stack<A,B>& rhs);
				template <class A, class B>
				friend bool operator<= (const stack<A,B>& lhs, const stack<A,B>& rhs);
				template <class A, class B>
				friend bool operator>  (const stack<A,B>& lhs, const stack<A,B>& rhs);
				template <class A, class B>
				friend bool operator>= (const stack<A,B>& lhs, const stack<A,B>& rhs);
	
	};
	//non-member funtion overload
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c == rhs.c;
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c != rhs.c;
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c < rhs.c;
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c <= rhs.c;
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c > rhs.c;
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c >= rhs.c;
	}
};

#endif