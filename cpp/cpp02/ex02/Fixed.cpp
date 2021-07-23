#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout<<"Default constructor called"<<std::endl;
	this->num = 0;
}
Fixed::Fixed(const Fixed &src)
{
	//std::cout<<"Copy constructor called"<<std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	//std::cout<<"Destructor called"<<std::endl;
}
Fixed &Fixed::operator=(const Fixed &src)
{
	
	//std::cout<<"Assignation operator called"<<std::endl;
	this->num =src.num;
	return (*this);
}

int Fixed::getRawBits( void ) const
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	return (this->num);
}

void Fixed::setRawBits( int const raw )
{
	//std::cout<<"getRawBits member function called"<<std::endl;
	this->num = raw;
}

Fixed::Fixed(const int data)
{
	//std::cout<<"Int constructor called"<<std::endl;
    this->num = data << this->bits;
}
Fixed::Fixed(const float data)
{
	//std::cout<<"Float constructor called"<<std::endl;
    this->num = roundf((float)data * (float)(1 << this->bits));
}
float Fixed::toFloat( void ) const
{
    float ret;
    ret = (float)this->num / (float)(1 << this->bits);
	return (ret);
}
int Fixed::toInt( void ) const
{
    int ret;
    ret = this->num>>this->bits;
    return (ret);
}

std::ostream &operator<<(std::ostream &ost, const Fixed &src)
{
	ost<<src.toFloat();
	return (ost);
}

int Fixed::operator>(const Fixed &right)
{
	Fixed &left = *this;
	return left.getRawBits() > right.getRawBits();
}
int Fixed::operator>=(const Fixed &right)
{
	Fixed &left = *this;
	return left.getRawBits() >= right.getRawBits();
}
int Fixed::operator<(const Fixed &right)
{
	Fixed &left = *this;
	return left.getRawBits() < right.getRawBits();
}
int Fixed::operator<=(const Fixed &right)
{
	Fixed &left = *this;
	return left.getRawBits() <= right.getRawBits();
}
int Fixed::operator==(const Fixed &right)
{
    Fixed &left = *this;
	return left.getRawBits() == right.getRawBits();
}
int Fixed::operator!=(const Fixed &right)
{
    Fixed &left = *this;
	return left.getRawBits() != right.getRawBits();
}

const Fixed &Fixed::operator+(const Fixed &src)
{
	this->setRawBits(this->getRawBits() + src.getRawBits());
	return (*this);
}

const Fixed &Fixed::operator-(const Fixed &src)
{
	this->setRawBits(this->getRawBits() - src.getRawBits());
	return (*this);
}

const Fixed &Fixed::operator*(const Fixed &right)
{
	Fixed &left = *this;
	long op1 = left.getRawBits();
	long op2 = right.getRawBits();
	this->setRawBits(((op2) * (op1)) / (1 << this->bits));
	return (*this);
}

const Fixed &Fixed::operator/( const Fixed &right)
{
	Fixed &left = *this;
	long op1 = left.getRawBits();
	long op2 = right.getRawBits();
	this->setRawBits(((op1 / op2) * (1 << this->bits))); 
	return (*this);
}

Fixed &Fixed::operator++()
{
	this->num++;
	return (*this);
}

const Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	this->num++;
	return (ret);
}

Fixed &Fixed::operator--()
{
	this->num--;
	return (*this);
}

const Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	this->num--;
	return (ret);
}

Fixed &Fixed::max(Fixed &s1, Fixed &s2)
{
	
	if (s1 >= s2)
		return (s1);
	else
		return (s2); 
}

const Fixed &Fixed::max(const Fixed &s1, const Fixed &s2)
{
	Fixed copy_s1(s1);
	Fixed copy_s2(s2);
	if (copy_s1 >= copy_s2)
		return (s1);
	else
		return (s2); 
}

Fixed &Fixed::min(Fixed &s1, Fixed &s2)
{
	
	if (s1 >= s2)
		return (s2);
	else
		return (s1);
	
}

const Fixed &Fixed::min(const Fixed &s1, const Fixed &s2)
{
	Fixed copy_s1(s1);
	Fixed copy_s2(s2);
	if (copy_s1 >= copy_s2)
		return (s2);
	else
		return (s1);
}