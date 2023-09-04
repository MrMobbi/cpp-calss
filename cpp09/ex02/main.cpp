
#include <iostream>
#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Please add an argument while runing the program" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe	test(av);
		test.displayList();
		test.startSolver();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
