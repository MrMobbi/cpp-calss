
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment;

	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " = " << it->second << "; ";
	 std::cout << '\n';
}

int	main(int	ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong Number of arguments" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	quentin("data.csv", static_cast<std::string>(av[1]));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
