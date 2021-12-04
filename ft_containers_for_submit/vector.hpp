#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <iterator>
#include <limits>

#include "etc.hpp"
#include <unistd.h>
namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

		class Iterator
		{
				class Const_iterator;
				public:
					typedef std::random_access_iterator_tag iterator_category;
					typedef T value_type;
					typedef int difference_type;
					typedef const T* const_pointer;
					typedef T* pointer;
					typedef const T& const_reference;
					typedef T& reference;

					Iterator(pointer ptr) : ptr(ptr) {}
					Iterator():ptr(NULL){}
					Iterator(const Iterator &src):ptr(src.base()) {}
					Iterator(const Const_iterator &other):ptr(other.base()) {}
					pointer base() const { return ptr; }
					reference operator*() const { return *ptr; }
					pointer operator->() { return ptr; }
					friend bool operator== (const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };
					friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };
					Iterator &operator=(const Iterator &src)
					{
						this->ptr =  src.ptr;
						return *this;
					}
					const Iterator &operator=(const Iterator &src) const
					{
						this->ptr =  src.ptr;
						return *this;
					}
					//forward-iterator
					Iterator& operator++() { ptr++;  return *this; }
					Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }

					//bidirection-iterator
					Iterator& operator--() { ptr--; return *this; }
					Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
					//LegacyRandomAccessIterator

					Iterator& operator+=(int n)
					{
						while (n < 0)
						{
							(*this)--;
							n++;
						}
						while (n > 0)
						{
							(*this)++;
							n--;
						}
						return (*this);
					};
					friend Iterator operator+ (const Iterator& a, int num) { Iterator temp(a); temp += num; return temp; }
					friend Iterator operator+ (int num, const Iterator& a) { return (a + num); }
					Iterator& operator-=(int n) { return (operator+=((-1) * n)); };
					Iterator operator-(int num) { Iterator temp(*this); temp -= num;  return temp; }
					friend difference_type operator- (const Iterator& a, const Iterator& b)
					{
						difference_type ret = 0;
						Iterator start = a, end = a;
						if (a.ptr < b.ptr)
							end = b;
						else
							start = b;
						while (start++ != end)
							ret++;
						if (end == b)
							ret *= -1;
						return ret;
					};
					/*friend difference_type operator-(const Iterator &lhs, const Iterator &rhs) 이런식으로 하면 안됨.
					{
						return std::distance(lhs, rhs);
					}*/
					const value_type &operator[](int diff) const
					{
						return *(ptr + diff);
					}
					value_type &operator[](int diff)
					{
						return *(ptr + diff);
					}
				private:
					pointer ptr;
					friend bool operator<(const Iterator& a, const Iterator &b) { return (b - a > 0); }
					friend bool operator>(const Iterator& a, const Iterator &b) { return  (b < a); }
					friend bool operator>=(const Iterator& a, const Iterator &b) { return !(a < b); }
					friend bool operator<=(const Iterator& a, const Iterator &b) { return !(a > b); }
			};
			typedef unsigned long size_type;
			typedef Iterator iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef Allocator allocator_type;
			typedef int difference_type;
			typedef T value_type;

		class Const_iterator
			{
				public:

					typedef std::random_access_iterator_tag iterator_category;
					typedef T value_type;
					typedef long int difference_type;
					typedef const T* pointer;
					typedef const T& reference;

					Const_iterator(pointer ptr) : ptr(ptr) {}
					Const_iterator():ptr(NULL){}
					Const_iterator( const Const_iterator &other):ptr(other.ptr) {}
					Const_iterator(const Iterator &other):ptr(other.base()) {}
					pointer base() const { return ptr; }
					const_reference operator*() const { return *ptr; }
					const_pointer operator->() const { return ptr; }
					friend bool operator== (const Const_iterator& a, const Const_iterator& b) { return a.ptr == b.ptr; };
					friend bool operator!= (const Const_iterator& a, const Const_iterator& b) { return a.ptr != b.ptr; };
					Const_iterator &operator=(const Const_iterator &src)
					{
						this->ptr =  src.ptr;
						return *this;
					}
					const Const_iterator &operator=(const Const_iterator &src) const
					{
						this->ptr =  src.ptr;
						return *this;
					}
					Const_iterator& operator++() { ptr++;  return *this; }
					Const_iterator operator++(int) { Const_iterator tmp = *this; ++(*this); return tmp; }

					Const_iterator& operator--() { ptr--; return *this; }
					Const_iterator operator--(int) { Const_iterator tmp = *this; --(*this); return tmp; }

					Const_iterator& operator+=(int n)
					{
						while (n < 0)
						{
							(*this)--;
							n++;
						}
						while (n > 0)
						{
							(*this)++;
							n--;
						}
						return (*this);
					};
					friend Const_iterator operator+ (const Const_iterator& a, int num) { Const_iterator temp(a); temp += num; return temp; }
					friend Const_iterator operator+ (int num, const Const_iterator& a) { return (a + num); }
					Const_iterator& operator-=(int n) { return (operator+=((-1) * n)); };
					Const_iterator operator-(int num) { Const_iterator temp(*this); temp -= num;  return temp; }
					friend difference_type operator- (const Const_iterator& a, const Const_iterator& b)
					{
						difference_type ret = 0;
						Const_iterator start = a, end = a;
						if (a.ptr < b.ptr)
							end = b;
						else
							start = b;
						while (start++ != end)
							ret++;
						if (end == b)
							ret *= -1;
						return ret;
					};
					const value_type &operator[](int diff) const
					{
						return *(ptr + diff);
					}
					value_type &operator[](int diff)
					{
						return *(ptr + diff);
					}
				private:
					const T *ptr;
					friend bool operator<(const Const_iterator& a, const Const_iterator &b) { return (b - a > 0); }
					friend bool operator>(const Const_iterator& a, const Const_iterator &b) { return  (b < a); }
					friend bool operator>=(const Const_iterator& a, const Const_iterator &b) { return !(a < b); }
					friend bool operator<=(const Const_iterator& a, const Const_iterator &b) { return !(a > b); }
			};
			typedef Const_iterator const_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		private:
			T *_array;
			size_type _capacity;
			size_type _size;
			Allocator _allocator;
			//size_type _allocator.max_size();

		protected:

		public:

			//Member functions
			vector():_capacity(0), _size(0), _allocator()
			{
				_array = _allocator.allocate(0);
			}

			explicit vector( const Allocator& alloc ):_capacity(0), _size(0), _allocator(alloc)
			{
				_array = _allocator.allocate(0);
			}

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()):_capacity(count), _size(count), _allocator(alloc)
			{
				if (count > _allocator.max_size())
					throw std::runtime_error("(vetor 생성자함수에서 발생) 할당할수 있는 크기를 넘어선 크기는 할당할수 없음.");
				_array = _allocator.allocate(_capacity);
				assign(count, value);
			}

			template< class InputIt >
			vector( InputIt first, typename ft::enable_if< !(ft::is_integral<InputIt>::value), InputIt >::type last, const Allocator& alloc = Allocator()):_capacity(0), _size(0), _allocator(alloc)
			{
				_array = _allocator.allocate(0);
				assign(first, last);
			}

			vector( const vector& other ):_capacity(other._capacity), _size(other._size), _allocator(other._allocator)
			{
				_array = _allocator.allocate(other.capacity());
				for (size_type i = 0; i < other.size(); i++){
					_allocator.construct(_array + i, other[i]);
				}
				_capacity = other.capacity();
				_size = other.size();
			}

			vector &operator=(const ft::vector<T> &src)
			{
				clear();//destroy를 안에서 호출하고 있음
				_allocator.deallocate(_array, _capacity);
				_array = _allocator.allocate(src.capacity());
				for (size_type i = 0; i < src.size(); i++){
					_allocator.construct(_array + i, src[i]);
				}
				_capacity = src.capacity();
				_size = src.size();
				//memcpy(_array, src.begin().base(), src.size() * sizeof(T));
				//assign(src.begin(), src.end());
				return *this;
			}
			~vector()
			{
				_allocator.destroy(_array);
				_allocator.deallocate(_array, _capacity);
			}
			void assign( size_type count, const T& value )
			{
				clear();
				insert(begin(), count, value);
			}
			template< class InputIt >
			void assign( InputIt first, typename enable_if< !(is_integral<InputIt>::value), InputIt >::type last )
			{
				clear();
				insert(begin(), first, last);
			}
			allocator_type get_allocator() const
			{
				return _allocator;
			}

			//Element access

			T &operator[](int idx) { return _array[idx];}
			const T &operator[](int idx) const { return _array[idx];}
			reference at( size_type pos )
			{
				if (pos > _size)
					throw std::runtime_error("Catch out_of_range exception!");
				return _array[pos];
			}
			const_reference at( size_type pos ) const
			{
				if (pos > _size)
					throw std::runtime_error("Catch out_of_range exception!");
				return _array[pos];
			}
			reference front() { return (*this)[0]; }
			const_reference front() const { return (*this)[0]; }
			reference back() { return _array[_size - 1]; }
			const_reference back() const { return _array[_size - 1]; }
			T* data() { return _array; }
			const T* data() const { return _array; }

			//Iterators

			Iterator begin()  { return Iterator(_array); }
			Const_iterator begin() const { return Const_iterator(_array); }
			Iterator end()  { return Iterator(&_array[_size]); }
			Const_iterator end() const  { return Const_iterator(&_array[_size]); }
			reverse_iterator rbegin() { return reverse_iterator(end()); }
			reverse_iterator rend() { return reverse_iterator(begin()); }
			const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
			const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

			//Capacity

			bool empty() const{ return (_size == 0); }
			size_type size() const{ return _size; }
			size_type capacity() const { return _capacity; }
			size_type max_size() const { return _allocator.max_size(); }
			void reserve( size_type new_cap )
			{
				if (new_cap > _allocator.max_size())
					throw std::runtime_error("(reserve함수에서) 들어온 인자의 크기가 할당할수 있는 크기보다 큼.");
				if (new_cap >= _capacity)
				{
					T *temp = _allocator.allocate(new_cap);
					memcpy(temp, _array, sizeof(T) * _size);
					_allocator.deallocate(_array, _capacity);
					_array = temp;
					_capacity = new_cap;
				}
			}

			//Modifiers

			void clear()
			{
				int num = _size - 1;
				for (;num >= 0; num--)
					_allocator.destroy(_array + num);
				_size = 0;
			}
			iterator insert( iterator pos, const T& value )
			{
				size_type diff = std::distance(begin(), pos);
				if (pos < begin() || end() < pos)
					throw std::runtime_error("( insert() 함수에서 ) pos가 정상적인 범위를 벗어남");

				size_type new_capacity = _capacity;
				if (new_capacity <= 0)
					new_capacity = 1;
				if (_size  + 1 > new_capacity)
					new_capacity = new_capacity * 2;
				if (new_capacity >= _allocator.max_size())
					throw std::runtime_error("(reserve함수에서) 들어온 인자의 크기가 할당할수 있는 크기보다 큼.");
				if (new_capacity != _capacity)
					reserve(new_capacity);

				pos = Iterator(&_array[diff]);

				memcpy(&*pos + 1, &*pos, sizeof(T) * std::distance(pos, end()));//<-여기서 consturcture 호출 하지 말것
				// *pos = value;
				_allocator.construct(&*pos, value);
				_size++;
				return pos;
			}
			void insert( iterator pos, size_type count, const T& value )
			{

				for (size_type i = count; i > 0; i--)
					pos = insert(pos, value);
			}
			template< class InputIt >
			void insert( iterator pos, typename enable_if < !(is_integral<InputIt>::value), InputIt >::type first, InputIt last)
			{
				if (first == last)
					return;
				last--;

				for (; last != first; --last)
				{
					pos = insert(pos, *last);
				}
				insert(pos, *first);
			}
			iterator erase( iterator pos )
			{
				size_type diff = std::distance(begin(), pos);
				memcpy(&*pos, &*pos + 1, sizeof(T) * std::distance(pos + 1, end()));
				_size--;
				return Iterator(&_array[diff]);
			}
			iterator erase( iterator first, iterator last )
			{
				size_type diff = std::distance(first, last);
				while (diff--)
					first = erase(first);
				return first;
			}
			void push_back( const T& value )
			{
				insert(end(), value);
			}
			void pop_back(){ _size--; }
			void resize( size_type count, T value = T() )
			{
				if (_size < count)
					insert(end(), count - _size, value);
				_size = count;
			}
			void swap( vector& other )
			{
				unsigned int size = other._size;
				Allocator allocator = other._allocator;
				unsigned int capacity = other._capacity;
				T * array = other._array;

				other._size = _size;
				other._allocator =_allocator;
				other._capacity = _capacity;
				other._array = _array;

				_size = size;
				_allocator =allocator;
				_capacity = capacity;
				_array = array;
			}
	};

	//Non-member functions
	template <typename T, class Allocator >
	bool operator==(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		typename ft::vector<T, Allocator>::const_iterator left_iter = left.begin(), right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end())
		{
			if (*left_iter != *right_iter)
				return false;
			left_iter++;
			right_iter++;
		}
		if (left_iter == left.end() && right_iter == right.end())
			return true;
		else
			return false;
	}
	template <typename T, class Allocator >
	bool operator!=(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		return !(left == right);
	}
	template <typename T, class Allocator >
	bool operator<=(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		typename ft::vector<T, Allocator>::const_iterator left_iter = left.begin(), right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end())
		{
			if (*left_iter == *right_iter)
			{
				left_iter++;
				right_iter++;
				continue;
			}
			else if (*left_iter > *right_iter)
				return false;
			else
				return true;
		}
		if (left_iter == left.end())
			return true;
		else
			return false;
	}
	template <typename T, class Allocator >
	bool operator<(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		typename ft::vector<T, Allocator>::const_iterator left_iter = left.begin(), right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end())
		{
			if (*left_iter == *right_iter)
			{
				left_iter++;
				right_iter++;
				continue;
			}
			else if (*left_iter > *right_iter)
				return false;
			else
				return true;
		}
		if (left_iter == left.end() && right_iter != right.end())
			return true;
		else
			return false;
	}
	template <typename T, class Allocator >
	bool operator>=(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		return !(left < right);
	}
	template <typename T, class Allocator >
	bool operator>(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		return !(left <= right);
	}
	template< class T, class Alloc >
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
};



#endif
