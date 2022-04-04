#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <iterator> // distance()
#include <limits>

#include "../etc/etc.hpp"
#include <unistd.h>

namespace ft //iterator_traits는 이 namespace에다가 정의하는게 맞긴한데...
{
	template <typename T, class Allocator = std::allocator<T> > //allocater가 아니라 allocator...! allocator에 T가 들어가는게 가장 중요함. 메모리 할당 단위를 결정하게 됨.
	class vector
	{
		public:

		class Iterator//iterator은 기본적으로 클래스이며.. 포인터를 내포한다.어댑터의 성격을 지닌다고 볼수있다.
			{//iterator class interface 어디에...?
			//https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator <- 여기에 interface 다 있음.
			//공식 레퍼런스 사이트를 쫌 참고하십시오....!
				public:
					typedef std::random_access_iterator_tag iterator_category;
					typedef T value_type;
					typedef int difference_type;
					typedef T* pointer;
					typedef T& reference;

					Iterator(pointer ptr) : ptr(ptr) { }//어댑터나 그 비슷한 것들... 즉 어떤 타켓 내포하는건 녀석들은, 타겟을 내포하려는 시도를 생성자측에서 시도하려고함.
					Iterator():ptr(NULL) {}
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
					const Iterator &operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
					
					//LegacyRandomAccessIterator
					Iterator& operator+=(int n)//std::sort() 함수에서 이 연산자를 요구함.
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
					Iterator operator-(int num) { Iterator temp(*this); temp -= num;  return temp; }//여기서 실수 있었음.
					friend difference_type operator- (const Iterator& a, const Iterator& b)//std::distance()함수가 이 연산자를 필요로 함.
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
						return (*(this + diff));
					}
					value_type &operator[](int diff)
					{
						return (*(this + diff));
					}
					friend bool operator<(const Iterator& a, const Iterator &b) { return (b - a > 0); }
					friend bool operator>(const Iterator& a, const Iterator &b) { return  (b < a); }
					friend bool operator>=(const Iterator& a, const Iterator &b) { return !(a < b); }
					friend bool operator<=(const Iterator& a, const Iterator &b) { return !(a > b); }
				private:
					pointer ptr;
			};
			/*
			class reverse_iterator//위에 Iterator 본문 복붙했는데, 수정이 필요한 부분 수정함.
			{//어댑터는 아님.(근데 어쨌거나 어댑터의 성질을 가지는건 사실임.)// reverse_iterator에 대해서 정리 잘 해놓기. "실제로 가리키는 것" <-> "내뱉어야하는 값"
				public:
					typedef std::random_access_iterator_tag iterator_category;
					//typedef std::bidirectional_iterator_tag iterator_category;
					typedef T value_type;
					typedef int difference_type;
					typedef T* pointer;
					typedef T& reference;

					reverse_iterator(pointer ptr) : ptr(ptr) {}//어댑터나 그 비슷한 것들... 즉 어떤 타켓 내포하는건 녀석들은, 타겟을 내포하려는 시도를 생성자측에서 시도하려고함.
					reverse_iterator():ptr(NULL){}
					reference operator*() const { return *ptr; }
					pointer operator->() { return ptr; }
					friend bool operator== (const reverse_iterator& a, const reverse_iterator& b) { return a.ptr == b.ptr; };
					friend bool operator!= (const reverse_iterator& a, const reverse_iterator& b) { return a.ptr != b.ptr; };
					reverse_iterator &operator=(const reverse_iterator &src)
					{
						this->ptr =  src.ptr;
						return *this;
					}
					const reverse_iterator &operator=(const reverse_iterator &src) const
					{
						this->ptr =  src.ptr;
						return *this;
					}
					//forward-iterator
					reverse_iterator& operator++() { ptr--;  return *this; }  //이렇게 잘만든 인터페이스가 10개의 인터페이스 안부럽다.
					reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }
					
					//bidirection-iterator
					reverse_iterator& operator--() { ptr++; return *this; }  
					const reverse_iterator &operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }
					//LegacyRandomAccessIterator

					reverse_iterator& operator+=(int n) //{ ptr += num;  return *this; }//operator+랑 똑같이 연산?//std::sort() 함수에서 이 연산자를 요구함.
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
					friend reverse_iterator operator+ (const reverse_iterator& a, int num) { reverse_iterator temp(a); temp += num; return temp; }
					friend reverse_iterator operator+ (int num, const reverse_iterator& a) { return (a + num); }
					reverse_iterator& operator-=(int n) { return (operator+=((-1) * n)); };
					reverse_iterator operator-(int num) { reverse_iterator temp(*this); temp -= num;  return temp; }//여기서 실수 있었음.
					friend difference_type operator- (const reverse_iterator& a, const reverse_iterator& b)//std::distance()함수가 이 연산자를 필요로 함.
					{
						difference_type ret = 0;
						reverse_iterator start = a, end = a;
						if (a.ptr < b.ptr)
							start = b;
						else
							end = b;
						while (start++ != end)
							ret++;
						if (end == a)
							ret *= -1;
						return ret;
					};
					//friend difference_type operator-(const reverse_iterator &lhs, const reverse_iterator &rhs) 이런식으로 하면 안됨.
					{
					//	return std::distance(lhs, rhs);
					//}
					const value_type &operator[](int diff) const
					{
						return (*(this + diff));
					}
					value_type &operator[](int diff)
					{
						return (*(this + diff));
					}
					friend bool operator<(const reverse_iterator& a, const reverse_iterator &b) { return (b - a > 0); }
					friend bool operator>(const reverse_iterator& a, const reverse_iterator &b) { return  (b < a); }
					friend bool operator>=(const reverse_iterator& a, const reverse_iterator &b) { return !(a < b); }
					friend bool operator<=(const reverse_iterator& a, const reverse_iterator &b) { return !(a > b); }
				private:
					pointer ptr;
			};*/
		
		//컨테이너 구현을 시작.

		private:
			T *_array;
			unsigned int _capacity;//특징 잘 파악하기(값이 늘어났으면 늘어났지 절대 줄어들지는 않는다.)
			unsigned int _size;
			//static const typename Allocator::value_type _max_size = std::allocator_traits<Allocator>::max_size;// / sizeof(T);//임의로 정하는게 맞는지...?
			static const unsigned long _max_size = 21474836481;
			Allocator _allocator;

		protected://애시당초 컨테이너는 상속을 염두에 두고 만들어지지 않았다.

		public:
		
			//typedef

			typedef unsigned int size_type;
			typedef Iterator iterator;
			typedef reverse_iterator reverse_iterator;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef Allocator allocator_type;
			typedef int difference_type;
			typedef T value_type;

			//Member functions
			//멤버변수는 총 5개이나, 생각해야할건 4개임.
			vector():_capacity(0), _size(0), _allocator()//Allocator의 기본생성자호출...
			{
				_array = _allocator.allocate(0);
			}

			explicit vector( const Allocator& alloc ):_capacity(0), _size(0), _allocator(alloc)
			{
				_array = _allocator.allocate(0);
			}

			explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()):_capacity(count), _size(count), _allocator(alloc)
			{
				if (count > _max_size)
					throw std::runtime_error("(vetor 생성자함수에서 발생) 할당할수 있는 크기를 넘어선 크기는 할당할수 없음.");//std::exeption의 생성자중에서 문자열을 인자로 받는 생성자는 없는듯
				_array = _allocator.allocate(_capacity);
				assign(count, value);
			}

			template< class InputIt >
			vector( InputIt first, typename ft::enable_if< !(ft::is_integral<InputIt>::value), InputIt >::type last, const Allocator& alloc = Allocator()):_capacity(0), _size(0), _allocator(alloc)
			{
				_array = _allocator.allocate(0);
				assign(first, last);
			} //템플릿 특수화로는 아까의 문제가 해결이 안됨.
			
			vector( const vector& other ):_capacity(other._capacity), _size(other._size), _allocator(other._allocator)
			{
				_array = _allocator.allocate(_capacity);
				assign(other.begin(), other.end());
			}

			vector &operator=(const ft::vector<T> &src)
			{
				_allocator.deallocate(_array, _capacity);
				_allocator = src._allocator;
				_size = src._size;
				_capacity = src._capacity;
				_array = _allocator.allocate(_capacity);
				assign(src.begin(), src.end());
				return *this;
			}

			~vector()
			{
				_allocator.deallocate(_array, _capacity);
			}

			void assign( size_type count, const T& value )
			{
				clear();
				insert(begin(), count, value);
			}

			template< class InputIt >
			void assign( InputIt first, typename enable_if< !(is_integral<InputIt>::value), InputIt >::type last ) //fitst > last이면 에러가 발생하게끔 구현. 반개구간임을 명심하자.
			{
				clear();
				insert(begin(), first, last);
			}
			allocator_type get_allocator() const
			{
				return _allocator;
			}

			//Element access

			T &operator[](int idx) { return _array[idx]; }
			const T &operator[](int idx) const { return _array[idx]; }
			reference at( size_type pos )
			{
				if (pos > _size)
					throw std::runtime_error("at 함수에서 input으로 들어온 pos가 정상적인 값이 아님");
				return _array[pos];
			}
			const_reference at( size_type pos ) const
			{
				if (pos > _size)
					throw std::runtime_error("at함수호출에서 input으로 들어온 pos가 정상적인 값이 아님");
				return _array[pos];
			}
			reference front() { return *this[0]; }
			const_reference front() const { return *this[0]; }
			reference back() { return _array[_size - 1]; }//빈 컨테이너에 대해서 이 함수호출하면 egmentation fault 뜨는건 표준이랑 완전히 동일함.
			const_reference back() const { return _array[_size - 1]; }
			T* data() { return _array; }
			const T* data() const { return _array; }

			//Iterators

			Iterator begin() const { return Iterator(_array); }//iterator은 뭔가를 내포하는거니까... 생성자에서 타켓을 인자로 받는게 당연하겠다..
			Iterator end() const  { return Iterator(&_array[_size]); } // [_size - 1]이 아니라 [_size]가 맞겠다.
			reverse_iterator rbegin() const { return reverse_iterator(&_array[_size]); }
			reverse_iterator rend() const { return reverse_iterator(&_array[0]); }

			//Capacity

			bool empty() const{ return (_size == 0); }
			size_type size() const{ return _size; }
			size_type capacity() const { return _capacity; }
			size_type max_size() const { return _max_size; }
			void reserve( size_type new_cap )
			{
				if (new_cap > _max_size)
					throw std::runtime_error("(reserve함수에서) 들어온 인자의 크기가 할당할수 있는 크기보다 큼.");
				if (new_cap >= _capacity)//어떻게 하는게 효율적인지 판단이 안됨.
				{
					T *temp = _allocator.allocate(new_cap);
					memcpy(temp, _array, sizeof(T) * _size);//bit copy?
					_allocator.deallocate(_array, _capacity);
					_array = temp;
					_capacity = new_cap;
				}
			}

			//Modifiers

			void clear() { _size = 0; } // 이렇게 하는게 맞음 표준에서도 이렇게 하는듯
			iterator insert( iterator pos, const T& value )//다른 insert함수들의 반환형이 void인 이유에 대해 생각해보기
			{
				size_type diff = std::distance(begin(), pos);//distance = (index_num - index_num)
				if (pos < begin() || end() < pos)//조건문 이게 맞음. 테스트 해봄.
					throw std::runtime_error("( insert() 함수에서 ) pos가 정상적인 범위를 벗어남");//여기 걸리는건 웬만해선 iterator갱신 안해준 잘못떄문임.
				
				size_type new_capacity = _capacity;
				if (new_capacity <= 0)
					new_capacity = 1;
				if (new_capacity >= _max_size)
					throw std::runtime_error("(reserve함수에서) 들어온 인자의 크기가 할당할수 있는 크기보다 큼.");
				if (_size  + 1 > _capacity)
					new_capacity = new_capacity * 2;
				if (new_capacity != _capacity)
					reserve(new_capacity);
				pos = Iterator(&_array[diff]);//reserve()를 했기때문에 iterator갱신이 필요함.
				
				//memcpy문제 발생할수 있음...
				memcpy(&*pos + 1, &*pos, sizeof(T) * std::distance(pos, end()));
				*pos = value;
				_size++;//cosnt 함수가 아니면 무조건 멤버변수에 변동이 있음.
				return pos;
			}
			void insert( iterator pos, size_type count, const T& value )
			{
				
				for (size_type i = count; i > 0; i--)
					pos = insert(pos, value);
			}
			template< class InputIt >
			void insert( iterator pos, typename enable_if< !( is_integral<InputIt>::value), InputIt >::type first, InputIt last)
			{
				last--;
				for (;last >= first; --last)
					pos = insert(pos, *last);
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
			void push_back( const T& value ) { insert(end(), value); }
			void pop_back(){ _size--; }
			void resize( size_type count, T value = T() )
			{
				if (_size < count)
					insert(end(), count - _size, value);
				_size = count;
			}
			void swap( vector& other )
			{
				vector temp(*this);
				*this = other;
				other = temp;
			}
		private:
			//friend bool operator==(const ft::vector &left, const ft::vector &right);
			//friend를 해줄 필요가 없다.
	};

	//Non-member functions
	template <typename T, class Allocator >
	bool operator==(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)
	{
		typename ft::vector<T, Allocator>::iterator left_iter = left.begin(), right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end())//끝에 도달해서 끝났냐 아니면 중간에 끝이났냐
		{
			if (*left_iter != *right_iter)
				break;
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
		typename ft::vector<T, Allocator>::iterator left_iter = left.begin(), right_iter = right.begin();
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
			else // *left_iter < *right_iter
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
		typename ft::vector<T, Allocator>::iterator left_iter = left.begin(), right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end())
		{
			if (*left_iter == *right_iter)
			{
				left_iter++;
				right_iter++;
				continue;//continue하는게 맞을듯.
			}
			else if (*left_iter > *right_iter)
				return false;
			else // *left_iter < *right_iter
				return true;
		}
		if (left_iter == left.end() && right_iter != right.end())//여기서 차이가 발생
			return true;
		else
			return false;
	}
	template <typename T, class Allocator >
	bool operator>=(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)//그냥 논리적으로 그럼...
	{
		return !(left < right);
	}
	template <typename T, class Allocator >
	bool operator>(const ft::vector<T, Allocator> &left, const ft::vector<T, Allocator> &right)//그냥 논리적으로 그럼...
	{
		return !(left <= right);
	}
	template< class T, class Alloc >//std::swap(function template) specialize..!
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs )
	{
		lhs.swap(rhs);
	}
};


#endif