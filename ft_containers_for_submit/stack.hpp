#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <typename T, typename Container = ft::vector <T> >
	class stack
	{

		protected:
			Container c;
		public:

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
