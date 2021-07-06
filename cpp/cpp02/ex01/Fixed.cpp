#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->num = 0;
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
	this->num =src.num;
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
	std::cout<<"getRawBits member function called"<<std::endl;
}

Fixed::Fixed(const int data)
{
	std::cout<<"Int constructor called"<<std::endl;
    this->num = data << this->bits;
}

Fixed::Fixed(const float data)
{
	std::cout<<"Float constructor called"<<std::endl;
    this->num = roundf((float)data * (float)(1 << this->bits));//float에 대하여 비트연산을 하면 당연히 안됨. 소수부를 다 0으로 만들것.
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
	ost.flush();//<<연산자 오버로딩시 플러쉬 하는 방법.
	return (ost);
}
