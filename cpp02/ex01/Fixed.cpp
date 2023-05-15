
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	this->_fixed_point = num << this->_fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	this->_fixed_point = roundf(num * float(1U << this->_fractional_bits)\
		   	+ (num >= 0 ? 0.5 : -0.5));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &t)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = t;
}

Fixed &Fixed::operator=(const Fixed &t)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixed_point = t.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "get_raw_bits member function called" << std::endl;
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const num)
{
	std::cout << "set_raw_bits member function called" << std::endl;
	this->_fixed_point = num << this->_fractional_bits;
}

float	Fixed::toFloat(void) const
{
	return (this->_fixed_point / float(1U << this->_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point >> this->_fractional_bits);	
}

std::ostream &operator<<(std::ostream &out, const Fixed &t)
{
	out << t.toFloat();
	return (out);
}
