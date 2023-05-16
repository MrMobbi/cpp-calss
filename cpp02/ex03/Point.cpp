
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::Point(const Point &t)
{
	*this = t;
}

Point	&Point::operator = (const Point &t)
{
	(void) t;
	std::cout << "Don't use a copy assignment operator for Point = Point";
	std::cout << " because value are in const and cannot be modified" << std::endl;
	return (*this);
}

Point::~Point(void)
{
}

const Fixed	&Point::getX(void) const
{
	return (this->_x);
}

const Fixed	&Point::getY(void) const
{
	return (this->_y);
}
