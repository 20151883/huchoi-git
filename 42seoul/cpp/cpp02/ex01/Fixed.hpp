#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
};

std::ostream &operator<<(std::ostream &ost, const Fixed &src);

# endif