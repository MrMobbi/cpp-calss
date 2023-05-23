
#include "Point.hpp"

float	area(Point const &a, Point const &b, Point const &c)
{
	return abs((a.getX() * (b.getY() - c.getY()) + b.getX() *\
				(c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool	check(Point const &a, Point const &b, Point const &c, Point const &point)
{
	if (point.getX() == a.getX() && point.getY() == a.getY())
		return (false);
	if (point.getX() == b.getX() && point.getY() == b.getY())
		return (false);
	if (point.getX() == c.getX() && point.getY() == c.getY())
		return (false);
	if ((point.getX() - a.getX()) / (b.getX() - a.getX()) ==\
			(point.getY() - a.getX()) / (b.getY() - a.getY()))
		return (false);
	if ((point.getX() - b.getX()) / (c.getX() - b.getX()) ==\
			(point.getY() - b.getX()) / (c.getY() - b.getY()))
		return (false);
	if ((point.getX() - c.getX()) / (a.getX() - c.getX()) ==\
			(point.getY() - c.getX()) / (a.getY() - c.getY()))
		return (false);
	return (true);
}

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point)
{
	float	area_1 = area(a, b, c);
	float	area_2 = area(point, b, c);
	float	area_3 = area(a, point, c);
	float	area_4 = area(a, b, point);

	if (check(a, b, c, point) == false)
		return (false);
	if (area_1 == area_2 + area_3 + area_4)
		return (true);
	else
		return (false);
}
