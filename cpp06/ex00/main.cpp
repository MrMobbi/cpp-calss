
#include <iostream>
#include <cmath>

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	
	float	nan_value;
	nan_value = nanf("0");
	std::cout << "nan_value [" << nan_value << "]" << std::endl;
	return (0);
}
