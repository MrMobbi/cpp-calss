
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
		vec.displayList(std::string("vector / before: "));
		vec.startSolver();
		vec.displayList(std::string("vector / after : "));
		PmergeMe<std::deque<int> >	deq(av);
		deq.displayList(std::string("deque / before : "));
		deq.startSolver();
		deq.displayList(std::string("deque / after: "));
		vec.displayTimeStamp(std::string("<vector>"));
		deq.displayTimeStamp(std::string("<deque>"));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
