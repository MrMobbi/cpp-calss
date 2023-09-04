
#include <iostream>
#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Please run it with some argument" << std::endl;
		return (1);
	}

	try
	{
		RPN	rpn(av);
		std::cout << "Displaying the class :" << std::endl;
		rpn.displayPrompt();
		std::cout << "Solver" << std::endl;
		rpn.solve();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
