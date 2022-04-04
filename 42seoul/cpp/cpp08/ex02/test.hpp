#include <iostream>
#include <deque>
/*template<typename T>
class Mystack_iterator
{
    Mystack<T>* current;
public:
    Mystack_iterator(Mystack<T>* p = 0) : current(p) {}

    inline Mystack_iterator& operator++(){
        current = current->next;
        return *this;
    }

    inline T& operator*()
    {
        return current->data;
    }

    inline bool operator==(const Mystack_iterator& p){ return current == p.current; }
    inline bool operator!=(const Mystack_iterator& p){ return current != p.current; }
};*/

template <class T, class Container = std::deque<T> >
class Mystack
{
	protected:
    	Container c;
	public:
		explicit Mystack(void)
		{}
		explicit Mystack(const Container& src)
		{
			c = src;
		}
		bool empty() const {
			return c.empty();
		}
		size_t size() const {
			return c.size();
		}
		T &top() {
			return c.back();
		}
		T &top() const {
			return c.back();
		}
		void push(const T& x) {
			c.push_back(x);
		}
		void push(T&& x) {
			c.push_back(std::move(x));
		}
		template <class... Args> void emplace(Args&&... args) {
			c.emplace_back(std::forward<Args>(args)...);
		}
		void pop() {
			c.pop_back();
		}
		//void swap(mutantstack& s) noexcept(noexcept(swap(c, s.c))) {
		//	using std::swap;
		//	swap(c, s.c);
		//}
		//typedef Mystack<T> iterator;
		template<typename T>
		class iterator
		{
			private:
 		   		std::deque<T>::iterator current;
			public:
   	 			iterator(std::deque<T>::iterator p = 0) : current(p) {}

    			inline iterator& operator++(){
					current++;
					return current;
    			}

    			inline T& operator*()
    			{
        			return *current;
    			}
    			inline bool operator==(const iterator& p){ return current == p.current; }
    			inline bool operator!=(const iterator& p){ return current != p.current; }
		};
		typename std::deque<T>::iterator begin()
			{return c.begin();}
		typename std::deque<T>::iterator end()
			{return c.end();}
};
