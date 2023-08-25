
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include "easyfind.hpp"

void	display_element(int element)
{
	std::cout << element << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		std::vector<int>	lst;

		for (int i = 10; i < 20; i++)
			lst.push_back(i);
		std::cout << "Displaying value in vector :" << std::endl;
		std::for_each(lst.begin(), lst.end(), display_element);
		std::cout << "testing function easyfind :" << std::endl;
		try
		{
			std::cout << "[" << *(easyfind(lst, std::atoi(av[1]))) << "]" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "]" << std::endl;
		}
	}
	else
		std::cout << "Please add a argument" << std::endl;
	return (0);
}
