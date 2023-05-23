
#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point	a(0,0);
	Point	b(10, 30);
	Point	c(20, 0);
	Point	p(1, 0);

	if (bsp(a, b, c, p) == true)
		std::cout << "Point inside" << std::endl;
	else
		std::cout << "Point outside" << std::endl;
	return (0);
}
