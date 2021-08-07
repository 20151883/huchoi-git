#include <iostream>
#include <vector>
#include <functional>
#include <memory>
#include <iterator> // distance()

namespace ft//iterator_traits는 이 namespace에다가 정의하는게 맞긴한데...
{
    template <typename T, class Allocator = std::allocator<T> > //allocater가 아니라 allocator...!
    class vector
    {
        public:

        class Iterator//기본적으로 클래스이며.. 포인터를 내부에 저장한다.
            {
                public:

                    typedef std::random_access_iterator_tag iterator_category;
                    //typedef std::bidirectional_iterator_tag iterator_category;
                    typedef T value_type;
                    typedef int difference_type;
                    typedef T* pointer;
                    typedef T& reference;

                    Iterator(pointer ptr) : ptr(ptr) {}//어댑터나 그 비슷한 것들, 즉 어떤 타켓 내포하는건 녀석들은, 타겟을 내포하려는 시도를 생성자측에서 시도하려고함.
                    Iterator():ptr(NULL){}
                    reference operator*() const { return *ptr; }
                    pointer operator->() { return ptr; }
                    Iterator& operator++() { ptr++;  return *this; }  
                    Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
                    Iterator& operator--() { ptr--; return *this; }  
                    Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
                    friend difference_type operator- (const Iterator& a, const Iterator& b)//std::distance()함수를 위해
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
                    Iterator operator+(int num) { Iterator temp(*this); temp += num;  return *this; }//여기서 실수 있었음.
                    
                    Iterator operator-(int num) { Iterator temp(*this); temp -= num;  return *this; }//여기서 실수 있었음.
                   
                    Iterator& operator+=(int n) //{ ptr += num;  return *this; }//operator+랑 똑같이 연산?
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
            static const unsigned int _max_size = 100000;//임의로 정하는게 맞는지...?
            Allocator _allocator;

        protected://애시당초 컨테이너는 상속을 염두에 두고 만들어지지 않았다.

        public:
            typedef unsigned int size_type;
            //생성자
            explicit vector(const Allocator &src = Allocator()):_capacity(0), _size(0), _allocator(src)
            {
                _array = _allocator.allocate(0);
            }
            explicit vector(size_type n, const Allocator &src = Allocator()):_capacity(n), _size(n), _allocator(src)
            {
                if (n > _max_size)
                    throw std::exception();//std::exeption의 생성자중에서 문자열을 인자로 받는 생성자는 없는듯
                _array = _allocator.allocate(n);
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = T();
            }
            template <class InputIterator>//******내부구현을 바꿔야함***** 암시적 인터페이스 유도 해야함.
            vector(InputIterator start, InputIterator end, const Allocator &src = Allocator() ):_allocator(src)
            {//반개구간임을 명심하자.
                typename InputIterator::difference_type diff =  std::distance(start, end);
                //std::cout<<diff<<std::endl;
                //while(1)
                //{}
                _array = _allocator.allocate(diff - 1);
                _size = diff - 1;
                _capacity = diff - 1;
                for (unsigned int i = 0; i < (unsigned int)(diff - 1); i++)
                    _array[i] = *(start++);
            }

            explicit vector(size_type n, const T &x = T(), const Allocator &src = Allocator()):_capacity(n), _size(n), _allocator(src)
            {
                if ((unsigned int)n > _max_size)
                    throw std::exception();
                _array = _allocator.allocate(n);
                for (unsigned int i = 0; i < _size; i++)//이거 대신에 assign()함수 쓰는게 더 좋음.
                    _array[i] = T(x);
            }
            
            //복사생성자
            vector(const ft::vector<T> &src):_capacity(src._capacity), _size(src._size), _allocator(src._allocator)
            {
                _array = _allocator.allocate(_capacity);
            }
            //대입연산자 오버로딩
            vector &operator=(const ft::vector<T> &src)
            {
                _allocator = src._allocator;
                _size = src._size;
                _array = _allocator.allocate(_size);
                _capacity = src._capacity;
            }
            //소멸자
            ~vector()
            {
                _allocator.deallocate(_array, _capacity);
            }
            //연산자오버로딩
            T &operator[](int idx)
            {
                //범위검사 하지 않는다.
                return _array[idx];
            }
            //non iterator system
            unsigned int size()
            {
                return _size;
            }
            unsigned int capacity()
            {
                return _capacity;
            }
            //iterator system
            Iterator begin() { return Iterator(_array); }//iterator은 뭔가를 내포하는거니까... 생성자에서 타켓을 인자로 받는게 당연하겠다..
            //아니 &_array[0]반환 하는 거랑 _array반환하는거랑 다를게 뭐지...?
            Iterator end()   { return Iterator(&_array[_size]); } // [_size - 1]이 아니라 [_size]가 맞겠다.
            reverse_iterator rbegin() { return reverse_iterator(&_array[_size]); }
            reverse_iterator rend() { return reverse_iterator(&_array[0]); }
            
    };
}
