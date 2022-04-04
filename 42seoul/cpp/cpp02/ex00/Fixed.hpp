#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int num;
        static const int bits = 8;
    public:
        Fixed();
		Fixed(const Fixed &src);//src 객체에서 const함수만 호출하면 되니까.
        ~Fixed();
		Fixed &operator=(const Fixed &src);//사용자정의 타입에 대해서는 참조자로 넘기는게 여러모로 효율적임. 그리고 대입연산자의 반환형은 *this의 참조형을 반환하는게 일반적임.
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
std::ostream &operator<<(std::ostream &ost, Fixed &src);
#endif