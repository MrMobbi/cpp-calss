
#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(const Point &t);
		Point &operator = (const Point &t);
		~Point(void);

		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;

		bool	bsp(Point const a, Point const b, Point const c, Point const point) const;

	private:
		Fixed const _x;
		Fixed const	_y;
};

#endif
