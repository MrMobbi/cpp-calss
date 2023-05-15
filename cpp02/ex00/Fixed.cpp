
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &t)
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

void	Fixed::setRawBits(int const raw)
{
	std::cout << "set_raw_bits member function called" << std::endl;
	this->_fixed_point = raw;
}
