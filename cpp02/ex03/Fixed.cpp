
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
}

Fixed::Fixed(const int num)
{
	this->_fixed_point = num << this->_fractional_bits;
}

Fixed::Fixed(const float num)
{
	this->_fixed_point = (num * float(1U << this->_fractional_bits)\
		   	+ (num >= 0 ? 0.5 : -0.5));
}

Fixed::Fixed(const Fixed &t)
{
	*this = t;
}

Fixed	&Fixed::operator = (const Fixed &t)
{
	this->_fixed_point = t.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const num)
{
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

bool	Fixed::operator < (const Fixed &t) const
{
	return (this->_fixed_point < t._fixed_point);
}

bool	Fixed::operator > (const Fixed &t) const
{
	return (this->_fixed_point > t._fixed_point);
}

bool	Fixed::operator <= (const Fixed &t) const
{
	return (this->_fixed_point <= t._fixed_point);
}

bool	Fixed::operator >= (const Fixed &t) const
{
	return (this->_fixed_point >= t._fixed_point);
}

bool	Fixed::operator == (const Fixed &t) const
{
	return (this->_fixed_point == t._fixed_point);
}

bool	Fixed::operator != (const Fixed &t) const
{
	return (this->_fixed_point != t._fixed_point);
}

Fixed	Fixed::operator + (const Fixed &t)
{
	return (Fixed(this->toFloat() + t.toFloat()));
}

Fixed	Fixed::operator - (const Fixed &t)
{
	return (Fixed(this->toFloat() - t.toFloat()));
}

Fixed	Fixed::operator / (const Fixed &t)
{
	return (Fixed(this->toFloat() / t.toFloat()));
}

Fixed	Fixed::operator * (const Fixed &t)
{
	return (Fixed(this->toFloat() * t.toFloat()));
}

//	empty parameter => PREFIX

Fixed	&Fixed::operator ++ (void)
{
	(this->_fixed_point)++;
	return (*this);
}

Fixed	&Fixed::operator -- (void)
{
	(this->_fixed_point)--;
	return (*this);
}

//	dummy parameter => POSTFIX
//	return THEN increments

Fixed	Fixed::operator ++ (int)
{
	// preserve the original state
	Fixed	tmp(*this);
	
	this->_fixed_point++;
	return (tmp);
}

Fixed	Fixed::operator -- (int)
{
	Fixed	tmp(*this);

	this->_fixed_point--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return (a <= b ? a : b); // "question" ? "true" : "false"
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() <= b.getRawBits() ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return (a >= b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() >= b.getRawBits() ? a : b);
}

std::ostream &operator<<(std::ostream &out, const Fixed &t)
{
	out << t.toFloat();
	return (out);
}
