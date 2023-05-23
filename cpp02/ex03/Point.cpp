
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
}

Point::Point(const Point &t) : _x(t.getX()), _y(getY())
{
}

Point	&Point::operator = (const Point &t)
{
	(void) t;
	return (*this);
}

Point::~Point(void)
{
}

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}
