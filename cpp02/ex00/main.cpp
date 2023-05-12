
#include "Fixed.hpp"

int	main(void)
{
	fixed	a;
	fixed	b(a);
	fixed	c;

	c = a;
	std::cout << a.get_raw_bits() << std::endl;
	std::cout << b.get_raw_bits() << std::endl;
	std::cout << c.get_raw_bits() << std::endl;
	return (0);
}
