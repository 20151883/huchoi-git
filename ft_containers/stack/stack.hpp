#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <typename T, typename container = ft::vector <T> >
	class stack
	{
		//private:
		//	container c;
		protected:
			container c;
		public:
			
			//typedef

			typedef typename container::value_type value_type;
			typedef container container_type;
			typedef typename container::size_type size_type;

			//memberfunction

			explicit stack (const container_type& ctnr = container_type()):c(ctnr) {}
			~stack() {}
			bool empty() const{ c.empty(); }
			size_type size() const{ return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push (const value_type& val) { c.push_back(val); }
			void pop( ){ c.pop_back(); }
			
			//non-member funtion overload

			friend bool operator== (const stack<T,container>& lhs, const stack<T,container>& rhs)
			{
				return lhs.c == rhs.c;
			}

			friend bool operator!= (const stack<T,container>& lhs, const stack<T,container>& rhs)
			{
				return lhs.c != rhs.c;
			}

			friend bool operator<  (const stack<T,container>& lhs, const stack<T,container>& rhs)
			{
				return lhs.c < rhs.c;
			}

			friend bool operator<= (const stack<T,container>& lhs, const stack<T,container>& rhs)
			{
				return lhs.c <= rhs.c;
			}

			friend bool operator>  (const stack<T,container>& lhs, const stack<T,container>& rhs)
			{
				return lhs.c > rhs.c;
			}

			friend bool operator>= (const stack<T,container>& lhs, const stack<T,container>& rhs)
			{
				return lhs.c >= rhs.c;
			}


	};
};

#endif