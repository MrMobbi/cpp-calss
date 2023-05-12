
#include "Fixed.hpp"

fixed::fixed(void)
{
	this->_fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

fixed::fixed(fixed &t)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = t;
}

fixed &fixed::operator=(const fixed &t)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_fixed_point = t.get_raw_bits();
	return (*this);
}

fixed::~fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	fixed::get_raw_bits(void) const
{
	std::cout << "get_raw_bits member function called" << std::endl;
	return (this->_fixed_point);
}

void	fixed::set_raw_bits(int const raw)
{
	std::cout << "set_raw_bits member function called" << std::endl;
	this->_fixed_point = raw;
}
