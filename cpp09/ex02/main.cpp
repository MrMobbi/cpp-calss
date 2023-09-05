
#include <iostream>
#include <vector>
#include "test.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Please add an argument while runing the program" << std::endl;
		return (1);
	}
	try
	{
		PmergeMe<std::vector<int> >	vec(av);
		vec.displayList(std::string("Vector : "));
		vec.startSolver();
		vec.displayList(std::string("Vector : "));
		PmergeMe<std::deque<int> >	deq(av);
		deq.displayList(std::string("Deque : "));
		deq.startSolver();
		deq.displayList(std::string("Deque : "));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
