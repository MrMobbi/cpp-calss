
#include "Point.hpp"


//    double denominator = ((b._y - c._y) * (a._x - c._x) + (c._x - b._x) * (a._y - c._y));
//    double a = ((b._y - c._y) * (point.x - c.x) + (c.x - b.x) * (p.y - c.y)) / denominator;
//    double b = ((c.y - a.y) * (point.x - c.x) + (a.x - c.x) * (point.y - c.y)) / denominator;
//    double c = 1 - a - b;

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{

    Fixed	denominator = ((b._y - c._y) * (a._x - c._x) + (c._x - b._x) * (a._y - c._y));
    Fixed	t_a = ((b._y - c._y) * (point.x - c.x) + (c.x - b.x) * (p.y - c.y)) / denominator;
    Fixed	t_b = ((c.y - a.y) * (point.x - c.x) + (a.x - c.x) * (point.y - c.y)) / denominator;
    Fixed	t_c = 1 - a - b;

	if (a >= 0 && b >= 0 && c >= 0)
		return (true);
	else
		return (false);
}
