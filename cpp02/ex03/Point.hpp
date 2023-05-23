
#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float const x, float const y);
		Point(const Point &t);
		Point &operator = (const Point &t);
		~Point(void);

		float	getX(void) const;
		float	getY(void) const;


	private:
		Fixed const _x;
		Fixed const	_y;
};

bool	bsp(Point const &a, Point const &b, Point const &c, Point const &point);

#endif
