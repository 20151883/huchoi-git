#ifndef ETC_HPP
#define ETC_HPP

#include <iostream>
#include <functional>
#include <memory>
#include <iterator> // distance()

namespace ft
{
	//iterator_traits

	template <class Iter>
	struct iterator_traits//알고리즘에서만 필요한줄 알았는데, 생각해보니 어댑터(reverse_iterator adapter)에서도 필요함.
	{
		public:
			typedef typename Iter::iterator_category iterator_category;
			typedef typename Iter::value_type value_type;
			typedef typename Iter::pointer pointer;
			//typedef typename Iter::const_pointer const_pointer;
			typedef typename Iter::reference reference;
			//typedef typename Iter::const_reference const_reference;
			typedef typename Iter::difference_type difference_type;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;
		typedef long difference_type;
	};

	//reverse_iterator (adpater!)

	template <class Iter>
	class reverse_iterator//기본적으로 어댑터임. -> 어댑터의 특징은?
	{
		public:

			//typedef (Member type이라고 부르자 이제)

			typedef Iter iterator_type;
			typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename ft::iterator_traits<Iter>::value_type value_type;
			typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
			typedef typename ft::iterator_traits<Iter>::pointer pointer;
			//typedef  typename ft::iterator_traits<Iter>::const_pointer const_pointer;
			typedef typename ft::iterator_traits<Iter>::reference reference;
			//typedef typename ft::iterator_traits<Iter>::const_reference const_reference;
		protected:
			//current 어떻게 만드는건지..? -> object라길래 어렵게 생각했는데 그냥 멤버변수임.
			iterator_type _current;
		public:
			//Member functions
			reverse_iterator() :_current() {}
			explicit reverse_iterator( iterator_type x ):_current(x) {}
			template< class U >
			reverse_iterator( const reverse_iterator<U>& other ):_current(other.base()) {} //잘 모르겠으나, cppreference에서 그냥 복사만 하면 된다고 얘기하니까 그냥 그대로 구현하면 될듯?
			//결국 U == Iter 이 되야하는거 아닌가...?
			template< class U >
			reverse_iterator& operator=( const reverse_iterator<U>& other ) //잘 모르겠으나, cppreference에서 그냥 복사만 하면 된다고 얘기하니까 그냥 그대로 구현하면 될듯?
			{
				_current = other.base();
				return *this;
			}
			iterator_type base() const { return _current; }
			//어댑터는 그 자체가 어떤 연산을 지원한다기 보단, 인터페이스를 0지원하는것임. 연산을 하고자 한다면 내포하는 녀석의 연산을 활용해야할것.
			//reference operator*() const { reverse_iterator temp = *this; Iter tmp = temp.base(); tmp; return *tmp;  /* Iter tmp = _current; return *--tmp;*/ }//뭔가 별로인거같은데, 표준에서는 이렇게 함수정의함.
			reference operator*() const
			{
				iterator_type tmp(_current);
				tmp--;
				return const_cast<reference>(*tmp);
			}
			pointer operator->() const { return &(operator*()); }
			value_type &operator[]( difference_type n ) const {return base()[-n-1]; } // const함수밖에 없는듯
			reverse_iterator &operator++(){ _current--; return *this; }//딱 하나만 잘 정의해 놓으면 됨.
			reverse_iterator<Iter> operator++( int ){ reverse_iterator ret(*this); ++(*this); return ret; }
			reverse_iterator &operator--(){ _current++; return *this; }
			reverse_iterator operator--( int ){ reverse_iterator ret(*this); --(*this); return ret; }
			//여기서 반환형 reverse_iterator<Iter> 이라고 하는거 아님.. 템플릿 안에는 < >가 모두 결정됐을때 들어온다는걸 생각하면...
			//reverse_iterator<Iter> 라고 해도 된다. 그냥 문법적으로 둘 다 가능함. 그러나 < >명시적으로 적는게 더 좋아보임.
			//라이브러리는 < >를 안 적는거보면.. 안적는게 좋은거 같기도 하고,.
			reverse_iterator &operator+=(int num)
			{
				if (num > 0)
				{
					for (; num != 0; num--)
						(*this)++;
				}
				else if (num < 0)
				{
					for (; num != 0; num++)
						(*this)--;
				}
				return *this;
			}
			reverse_iterator &operator-=(int num) { return (operator+=((-1) * num)); }
			reverse_iterator operator+(difference_type n) const
			{
				return reverse_iterator(base() - n);
			}
			reverse_iterator operator-(difference_type n) const
			{
				return reverse_iterator(base() + n);
			}
			//private: 비멤버함수를 friend선언 해주려했는데, 생각해보니 reverse_iterator에서는 그럴 필요가 없음
	};

	//표준에서 반한값 저렇게만 해주면 된다고 하는데.. iter1, iter2의 자료형이 다르면 저 연산이 어떻게 가능..? -> don't care
	template< class Iterator1, class Iterator2 >
	bool operator==( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){ return (lhs.base() == rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator!=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){ return (lhs.base() != rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator<=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){ return (lhs.base() >= rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator<( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){ return (lhs.base() > rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator>=( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){ return (lhs.base() <= rhs.base()); }
	template< class Iterator1, class Iterator2 >
	bool operator>( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs ){ return (lhs.base() < rhs.base()); }
	template< class Iter >
	reverse_iterator<Iter> operator+( typename reverse_iterator<Iter>::difference_type n,const reverse_iterator<Iter>& it ) { return (reverse_iterator<Iter>(it.base() - n)); }
	template< class Iterator >
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs ) { return (rhs.base() - lhs.base()); }
	//솔직히 namespace ft에서 위와같은 시그니쳐를 가진 템플릿이 많은데... 컴파일러가 잘 파악할수 있을까...? <- 아마 여기도 enable_if 해줘야할듯.

	//enable_if

	template <bool, typename T = void>//일반화 템플릿 버전
	struct enable_if {};

	template <typename T>//템플릿 특수화 버전
	struct enable_if<true, T> {
		typedef T type;
	};


	template <typename T>
	struct is_integral{
		const static bool value = false;
	};

	template <>
	struct is_integral<int>{
		const static bool value = true;
	};

	template <>
	struct is_integral<unsigned int>{
		const static bool value = false;
	};

	template <>
	struct is_integral<long>{
		const static bool value = true;
	};

	template <>
	struct is_integral<unsigned long>{
		const static bool value = false;
	};


	/*template <bool, typename T = void>
	struct is_integral {};

	template <typename T>
	struct is_integral<true, T> {
		typedef true value;
	};*/

	//equal

	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
				return false;
		}
		return true;
	}
	template< class InputIt1, class InputIt2, class BinaryPredicate >
	bool equal( InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p )
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!p(*first1, *first2))
				return false;
		}
		return true;
	}

	//lexicographical_compare

	template<class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (*first1 < *first2) return true;
			if (*first2 < *first1) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template<class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for ( ; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2 ) {
			if (comp(*first1, *first2)) return true;
			if (comp(*first2, *first1)) return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	//pair

	template <class T1, class T2>
	struct pair
	{
		public:

			//member type

			typedef T1 first_type;
			typedef T2 second_type;

			//member Object

			T1 first;
			T2 second;

			//member function

			pair():first(), second() {}
			pair( const T1& x, const T2& y ):first(x), second(y) {}
			//U1 = typename ft::enable_if<is_integral<U1>::value , U1 >::type
			template< class U1, class U2 > // 위에서 한 typedef도 변경해 줘야하는지..?
			pair( const pair<U1, U2>& p ):first(p.first), second(p.second) { }
			//pair( const pair <  typename enable_if< !(is_integral<U1>::value), U1 >::type, typename enable_if< !(is_integral<U2>::value) , U2 >::type  > & p ) :first(p.first), second(p.second) {}
			//이렇게 할 필요가 없었는데.....
			pair( const pair& p ) : first(p.first), second(p.second) {}
			pair& operator=( const pair& other )
			{
				first = other.first;
				second = other.second;
				return *this;
			}

		private:

			/*template <class A, class B>
			friend bool operator==( const ft::pair<A,B>& lhs, const ft::pair<A,B>& rhs );
			template <class A, class B>
			friend bool operator!=( const ft::pair<A,B>& lhs, const ft::pair<A,B>& rhs );
			template <class A, class B>
			friend bool operator>=( const ft::pair<A,B>& lhs, const ft::pair<A,B>& rhs );
			template <class A, class B>
			friend bool operator>( const ft::pair<A,B>& lhs, const ft::pair<A,B>& rhs );
			template <class A, class B>
			friend bool operator<=( const ft::pair<A,B>& lhs, const ft::pair<A,B>& rhs );
			template <class A, class B>
			friend bool operator<( const ft::pair<A,B>& lhs, const ft::pair<A,B>& rhs );
			애시당초 멤버변수가 public으로 선언되었기 때문에 friend선언이 불필요함.*/

	};

	template <class T1, class T2>
	bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first == rhs.first && lhs.second == rhs.second)
			return true;
		else
			return false;
	}
	template <class T1, class T2>
	bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs == rhs);
	}
	template <class T1, class T2>
	bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(lhs < rhs);
	}
	template <class T1, class T2>
	bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return rhs < lhs;
	}
	template <class T1, class T2>
	bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		return !(rhs < lhs);
	}
	template <class T1, class T2>
	bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
	{
		if (lhs.first < rhs.first)
			return true;
		else if (lhs.first > rhs.first)
			return false;
		else if (lhs.second < rhs.second)
			return true;
		else
			return false;
	}

	//make_pair

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 src1, T2 src2)//인자추론 유도
	{
		pair<T1, T2> ret(src1, src2);
		return ret;
	}
};

#endif
