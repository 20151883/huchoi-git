#include <iostream>
#include <algorithm>
#include <functional>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack : public Container//여기서 상속받는건 오직 "std::stack<int> s(mstack); "를 컴파일 시키기 위해서...
{
    private:
        Container source;
    public:
        /*class iterator{//iterator class 딱 이정도만 정의해 놓으면 되나...? 더 필요할거 같은데...
            typedef typename Container::iterator::iterator_category iterator_category;
            typedef typename Container::iterator::value_type value_type;
            typedef typename Container::iterator::differnce_type difference_type;
            typedef typename Container::iterator::pointer pointer;
            typedef typename Container::iterator::reference reference;
        };*/
        typedef typename Container::iterator iterator;

        typedef typename Container::size_type size_type;
        typedef typename Container::value_type value_type;
    
        MutantStack(const Container &src = Container())//어댑터니까!!
        {
            this->source = src;
        }

        bool empty() const
        {
            return this->source.empty();
        }
        typename Container::size_type size() const
        {
            return this->source.size();
        }
        void push(const value_type &src)
        {
            this->source.push_back(src);
        }
        void pop()
        {
            this->source.pop_back();
        }
        typename Container::value_type &top()
        {
            return this->source.back();
        }
        const typename Container::value_type &top() const
        {
            return this->source.back();
        }

        iterator begin()
        {
            return this->source.begin();
        }

        iterator end()
        {
            return this->source.end();
        }   
        /*bool operator==(const MutantStack &src)
        {

        }
        bool operator!=(const MutantStack &src)
        {

        }
        bool operator>=(const MutantStack &src)
        {

        }
        bool operator<=(const MutantStack &src)
        {

        }
        bool operator>(const MutantStack &src)
        {

        }
        bool operator<(const MutantStack &src)
        {

        }*/
        
};
