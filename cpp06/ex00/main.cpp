
#include <iostream>
#include "value.h"
#include "ScalarConvert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter 1 argument with the program" << std::endl;
		return (1);
	}
	ScalarConvert::convert(av[1]);
	return (0);
}
