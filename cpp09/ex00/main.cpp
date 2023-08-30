
#include <iostream>
#include <string>
#include "BitcoinExchange.hpp"

void print_map(std::string comment, const std::map<std::string, std::string> &m)
{
    std::cout << comment << std::endl;

	for (std::map<std::string, std::string>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " = " << it->second << "; " << std::endl;
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

		print_map("Printing Data", quentin.getData());
		print_map("Printing Wallet", quentin.getWallet());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
