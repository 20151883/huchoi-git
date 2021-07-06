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
		Fixed(Fixed &src);
        ~Fixed();
		Fixed &operator=(Fixed &src);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
std::ostream &operator<<(std::ostream &ost, Fixed &src);
#endif