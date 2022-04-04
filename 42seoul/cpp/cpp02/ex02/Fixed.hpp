#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
		int num;
		static const int bits = 8;
    public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed &operator=(const Fixed &src);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		int operator>(const Fixed &right);
		int operator>=(const Fixed &right);
		int operator<(const Fixed &right);
		int operator<=(const Fixed &right);
		int operator==(const Fixed &right);
		int operator!=(const Fixed &right);
		const Fixed &operator+(const Fixed &right);
		const Fixed &operator-(const Fixed &right);
		const Fixed &operator*(const Fixed &right);
		const Fixed &operator/(const Fixed &right);
		Fixed &operator++();
		const Fixed operator++(int);
		Fixed &operator--();
		const Fixed operator--(int);
		static Fixed &max(Fixed &s1, Fixed &s2);//함수에 static 키워드를 붙이는 이유는?
		static const Fixed &max(const Fixed &s1, const Fixed &s2);
		static Fixed &min(Fixed &s1, Fixed &s2);
		static const Fixed &min(const Fixed &s1, const Fixed &s2);
};

std::ostream &operator<<(std::ostream &ost, const Fixed &src);

#endif