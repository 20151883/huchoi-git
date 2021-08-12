#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <iterator> // distance()

#include "../etc/etc.hpp"
#include <unistd.h>
namespace ft//iterator_traits는 이 namespace에다가 정의하는게 맞긴한데...
{
	template <typename T, class Allocator = std::allocator<T> > //allocater가 아니라 allocator...! allocator에 T가 들어가는게 가장 중요함. 메모리 할당 단위를 결정하게 됨.
	class vector
	{
		public:

		class Iterator//기본적으로 클래스이며.. 포인터를 내포한다.
			{
				public:

					typedef std::random_access_iterator_tag iterator_category;
					//typedef std::bidirectional_iterator_tag iterator_category;
					typedef T value_type;
					typedef int difference_type;
					typedef T* pointer;
					typedef T& reference;

					Iterator(pointer ptr) : ptr(ptr) {}//어댑터나 그 비슷한 것들... 즉 어떤 타켓 내포하는건 녀석들은, 타겟을 내포하려는 시도를 생성자측에서 시도하려고함.
					Iterator():ptr(NULL){}
					reference operator*() const { return *ptr; }
					pointer operator->() { return ptr; }
					Iterator& operator++() { ptr++;  return *this; }  
					Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
					Iterator& operator--() { ptr--; return *this; }  
					Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
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
					friend bool operator== (const Iterator& a, const Iterator& b) { return a.ptr == b.ptr; };
					friend bool operator!= (const Iterator& a, const Iterator& b) { return a.ptr != b.ptr; };	 
					//아래부분... reverse_iterator에 추가 해줘야함.
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
					Iterator operator+(int num) { Iterator temp(*this); temp += num;  return temp; }//여기서 실수(status를 변경하는게 아닌 함수인데, status를 변경할려고 듦) 있었음.

					Iterator operator-(int num) { Iterator temp(*this); temp -= num;  return temp; }//여기서 실수 있었음.

					Iterator& operator+=(int n) //{ ptr += num;  return *this; }//operator+랑 똑같이 연산?//std::sort() 함수에서 이 연산자를 요구함.
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
					Iterator& operator-=(int n) //{ ptr -= num;  return *this; }
					 {
						while (n > 0)
						{
							(*this)--;
							n--;
						}
						while (n < 0)
						{
							(*this)++;
							n++;
						}
						return (*this);
					};
					const value_type &operator[](int n) const
					{
						return (*(*this + n));
					}
					value_type &operator[](int n)
					{
						return (*(*this + n));
					}
					bool operator>(const Iterator& a) { return this->ptr > a.ptr; }  
					bool operator<(const Iterator& a) { return this->ptr < a.ptr; }  
					bool operator>=(const Iterator& a) { return this->ptr >= a.ptr; }  
					bool operator<=(const Iterator& a) { return this->ptr <= a.ptr; }  
				private:
					pointer ptr;
			};
			class reverse_iterator
			{
				public:
					typedef std::random_access_iterator_tag iterator_category;
					//typedef std::bidirectional_iterator_tag iterator_category;
					typedef T value_type;
					typedef int difference_type;
					typedef T* pointer;
					typedef T& reference;

					reverse_iterator(pointer ptr):ptr(ptr){}
					reverse_iterator():ptr(NULL){}
					reference operator*() const { return *(ptr - 1); }
					pointer operator->() { return (ptr - 1); }
					reverse_iterator& operator++() { ptr--;  return *this; }  
					reverse_iterator operator++(int) { reverse_iterator tmp = *this; ++(*this); return tmp; }//여기서 실수 있었음
					reverse_iterator& operator--() { ptr++; return *this; }  
					reverse_iterator operator--(int) { reverse_iterator tmp = *this; --(*this); return tmp; }//여기서 실수 있었음
					friend difference_type operator- (const reverse_iterator& a, const reverse_iterator& b) 
					{
						difference_type ret = 0;
						reverse_iterator start = a, end = a;
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
					friend bool operator== (const reverse_iterator& a, const reverse_iterator& b) { return (a.ptr - 1) == (b.ptr - 1); };
					friend bool operator!= (const reverse_iterator& a, const reverse_iterator& b) { return (a.ptr - 1) != (b.ptr - 1); };

					private:
						pointer ptr;
			};
		private:
			T *_array;
			unsigned int _capacity;//특징 잘 파악하기(값이 늘어났으면 늘어났지 절대 줄어들지는 않는다.)
			unsigned int _size;
			static const unsigned long _max_size = 21474836471;//임의로 정하는게 맞는지...?
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
			typedef unsigned int difference_type;
			typedef T value_type;

			//Member functions
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

			//가불기 상태...! => enable_if 사용해서 해결하면 될듯. -> 일단은 해결함
			//enable_if, is_itegral 구현, 사용법 공부하기
			//template< class InputIt>
			//template< class InputIt, typename std::enable_if< !(std::is_integral<InputIt>::value), InputIt >::type* >

			//template <class InputIt>
			template< class InputIt >
			vector( InputIt first, typename ft::enable_if< !(ft::is_integral<InputIt>::value), InputIt >::type last, const Allocator& alloc = Allocator()):_capacity(0), _size(0), _allocator(alloc)
			{
				_array = _allocator.allocate(0);
				assign(first, last);
			}

			/*template <>
			vector( int first, int last, const Allocator& alloc = Allocator() ):_capacity(0), _size(0), _allocator(alloc)
			{
				_array = _allocator.allocate(0);
				std::cout <<"???"<<std::string(typeid(last).name()) << std::endl;
				if (std::string(typeid(last).name()) == "i" || std::string(typeid(last).name()) == "j")
				{
					std::cout << "reach" <<std::endl;
					for (size_type i = 0; i < first; i++)
						insert(begin(), last);
					return;
				}
			}*/
			
			vector( const vector& other ):_capacity(other._capacity), _size(other._size), _allocator(other._allocator)
			{
				_array = _allocator.allocate(_capacity);
				assign(other.begin(), other.end());
			}

			vector &operator=(const ft::vector<T> &src)
			{
				_allocator = src._allocator;
				_size = src._size;
				_allocator.deallocate(_array, _capacity);
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
			void assign( InputIt first, InputIt last ) //fitst > last이면 에러가 발생하게끔 구현. 반개구간임을 명심하자.
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
			reference back() { return _array[_size - 1]; }
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

			void clear() { _size = 0; }
			iterator insert( iterator pos, const T& value )
			{
				size_type diff = std::distance(begin(), pos);//distance = (index_num - index_num)
				if (pos < begin() || end() < pos)//조건문 이게 맞음. 테스트 해봄.
					throw std::runtime_error("( insert() 함수에서 ) pos가 정상적인 범위를 벗어남");//여기 걸리는건 웬만해선 iterator갱신 안해준 잘못떄문임.
				size_type new_capacity = _capacity;
				if (new_capacity <= 0)
					new_capacity = 1;
				if (_size  + 1 > _capacity)
					new_capacity = new_capacity * 2;
				if (new_capacity >= _max_size)
					throw std::runtime_error("(reserve함수에서) 들어온 인자의 크기가 할당할수 있는 크기보다 큼.");
				if (new_capacity != _capacity)
					reserve(new_capacity);
				_capacity = new_capacity;//여기서 위 블록 살짝 복잡할수 있음.
				pos = Iterator(&_array[diff]);
				//memcpy문제 발생할수 있음...
				memcpy(&*pos + 1, &*pos, sizeof(T) * std::distance(pos, end()));
				/*
				이 로직은 확실은 문제가 발생하지는 않음.
				for (Iterator iter(&_array[_size]); iter != pos; iter--)//for문안에서 뭔가 잘못됐었음. 아마 연산자 오버로딩 잘못 정의한듯..?
				{
					iterator tmp = iter;
					tmp--;
					*iter = *tmp;
					//std::cout<<*iter<<", ??"<<*(iter - 1)<<", "<< tmp<<", ";
					// *iter = *(iter - 1);
					std::cout<<*iter<<std::endl;
					//std::cout<<&*iter<<", "<<&pos<<std::endl;
					//sleep(1);
				}
				*/
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
			void insert( iterator pos, InputIt first, InputIt last)//first > last 이면 에러가 발생. 반개구간임을 명심하자
			{
				last--;
				for (;last >= first; --last)
				{
					pos = insert(pos, *last);//iterator 반환하는 함수가 극소수인 이유
				}
			}
			iterator erase( iterator pos )
			{
				//memcpy버그 발생할 수도 있음.
				size_type diff = std::distance(begin(), pos);
				memcpy(&*pos, &*pos + 1, sizeof(T) * std::distance(pos + 1, end()));

				_size--;
				return Iterator(&_array[diff]);
				//return pos;
			}
			iterator erase( iterator first, iterator last )
			{
				size_type diff = std::distance(first, last);
				std::cout<<"diff : "<<diff<<std::endl;
				while (diff--)
				{
					first = erase(first);
				}
				return first;
			}
			void push_back( const T& value ) { insert(end(), value);}
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

			//Non-member functions 이거도 구현해야하나...? 해야할듯.
			friend bool operator==(const vector &left, const vector &right)
			{
				iterator left_iter = left.begin(), right_iter = right.begin();
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
			friend bool operator!=(const vector &left, const vector &right)
			{
				return !(left == right);
			}
			friend bool operator<=(const vector &left, const vector &right)
			{
				iterator left_iter = left.begin(), right_iter = right.begin();
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
			friend bool operator<(const vector &left, const vector &right)
			{
				iterator left_iter = left.begin(), right_iter = right.begin();
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
			friend bool operator>=(const vector &left, const vector &right)//그냥 논리적으로 그럼...
			{
				return !(left < right);
			}
			friend bool operator>(const vector &left, const vector &right)
			{
				return !(left <= right);
			}
	};
};
#endif