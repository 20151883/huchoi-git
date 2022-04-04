#include <deque>
#include <iostream>
using namespace std;

template<typename T>
class slist_iterator
{
    Node<T>* current;
public:
    slist_iterator(Node<T>* p = 0) : current(p) {}

    inline slist_iterator& operator++(){
        current = current->next;
        return *this;
    }

    inline T& operator*()
    {
        return current->data;
    }

    inline bool operator==(const slist_iterator& p){ return current == p.current; }
    inline bool operator!=(const slist_iterator& p){ return current != p.current; }
};

template <class T, class Container = std::deque<T> >
class mutantstack {
 public:
    typedef typename Container::value_type value_type;
    typedef typename Container::reference reference;
    typedef typename Container::const_reference const_reference;
    typedef typename Container::size_type size_type;
    typedef Container container_type;

 protected:
    Container c;

 public:
    explicit mutantstack(const Container&);
    explicit mutantstack(Container&& = Container());
    template <class Alloc> explicit mutantstack(const Alloc&);
    template <class Alloc> mutantstack(const Container&, const Alloc&);
    template <class Alloc> mutantstack(Container&&, const Alloc&);
    template <class Alloc> mutantstack(const mutantstack&, const Alloc&);
    template <class Alloc> mutantstack(mutantstack&&, const Alloc&);

    bool empty() const {
        return c.empty();
    }
    size_type size() const {
        return c.size();
    }
    reference top() {
        return c.back();
    }
    const_reference top() const {
        return c.back();
    }
    void push(const value_type& x) {
        c.push_back(x);
    }
    void push(value_type&& x) {
        c.push_back(std::move(x));
    }
    template <class... Args> void emplace(Args&&... args) {
        c.emplace_back(std::forward<Args>(args)...);
    }
    void pop() {
        c.pop_back();
    }
    void swap(mutantstack& s) noexcept(noexcept(swap(c, s.c))) {
        using std::swap;
        swap(c, s.c);
    }
};
