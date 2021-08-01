#include <iostream>
#include <vector>

namespace ft
{
    template <typename T, typename allocator = std::allocater<T>>
    class vector
    {
        private:

        protected:

        public:
            //생성자
            vector();
            vector(int n);
            vector(int n, T x);
            vector(typename ft::vector<T>::iterator start, typename ft::vector<T>::iterator end);
            //복사생성자
            vector(const ft::vector &src);
            //대입연산자 오버로딩
            vector &operator=(const vector &src);
            //소멸자
            ~vector();
            //연산자오버로딩

            //non iterator system

            //iterator system

    }
}
