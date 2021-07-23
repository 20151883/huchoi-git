#include "Fixed.hpp"

Fixed::Fixed(int num = 0)
{
	std::cout<<"Default constructor called"<<std::endl;
	this->num = num;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed &Fixed::operator=(const Fixed &src)
{
	
	std::cout<<"Assignation operator called"<<std::endl;
	this->num =src.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->num);
}

void Fixed::setRawBits( int const raw )
{
	this->num = raw;
	std::cout<<"setRawBits member function called"<<std::endl;
}

std::ostream &operator<<(std::ostream &ost, Fixed &src)
{
	ost<<src.getRawBits();
	ost.flush();
	return (ost);
}