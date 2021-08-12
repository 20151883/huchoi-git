#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <iterator> // distance()
#include "../etc/etc.hpp"

namespace ft
{
	template <typename key, typename T, class Compare = std::less<key>, class Allocator = std::allocator<pair<key, T> > >
	class map
	{
		private:
			pair<key, value> *arr;
			Allocator _allocator;

		public:
			//Member classes
			class value_compare
			{
				public:
					typedef bool result_type;
					typedef key first_argument_typ;
					typedef T second_argument_typ;
				protected:
					Compare comp;
					value_compare(Compare c):comp(c) {}//생성자를 왜 protected에다가...?
				public:
					bool operator()( const value_type& lhs, const value_type& rhs ) const { return comp(lhs.first, rhs.first); }
			};
			//Member functions
			map();
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
			map( const map& other );
			~map();
	};
};

#endif