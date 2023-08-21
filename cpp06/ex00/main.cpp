
#include <iostream>
#include "ScalarConvert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please enter 1 argument with the program" << std::endl;
		return (1);
	}
	try		
	{ ScalarConvert::convert(av[1]); }
	catch (std::exception &e)
	{ std::cout << e.what() << std::endl; }
	return (0);
}
