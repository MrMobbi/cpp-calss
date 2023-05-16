
#include "Fixed.hpp"

int	main(void)
{
	std::cout << std::endl;
	Fixed	a;
	Fixed	b(Fixed(2.05f) / Fixed(0.08f));
	Fixed	c;

	std::cout << "a is " << a << std::endl;
	std::cout << "a is " << ++a << std::endl;
	std::cout << "a is " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;

	c = --a;

	std::cout << "a is " << a << std::endl;
	std::cout << "c is " << c << std::endl;

	std::cout << "b is " << b << std::endl;

	Fixed const	z(2.43f);
	Fixed const	y(2.3f);

	std::cout << Fixed::max(a, b) << std::endl;
	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << Fixed::min(z, y) << std::endl;
	std::cout << Fixed::max(z, y) << std::endl;
	return (0);
}
