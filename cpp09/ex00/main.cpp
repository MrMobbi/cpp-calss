
#include <iostream>
#include <string>
#include <cctype>
#include <map>
#include <algorithm>
#include <ctime>
#include <sstream>
#include "BitcoinExchange.hpp"

void printMap(std::string comment, const std::map<std::string, std::string> &m)
{
    std::cout << comment << std::endl;

	for (std::map<std::string, std::string>::const_iterator it = m.begin(); \
			it != m.end(); it++)
		std::cout << it->first << " = " << it->second << "; " << std::endl;
	 std::cout << '\n';
}

template<typename t_iter>
void	displayExchange(t_iter &needle, t_iter &closest)
{
			std::cout << needle->first << " => " << needle->second << " = ";
			std::cout << std::atof(needle->second.c_str()) * \
				std::atof(closest->second.c_str()) << std::endl;
}

template<typename t_iter>
bool	isValidWallet(t_iter &needle)
{
	(void) needle;
	return (true);
}

template<typename t_map>
void	exchange(const t_map &data, const t_map &wallet)
{
	std::map<std::string, std::string>::const_iterator	needle = wallet.begin();
	std::map<std::string, std::string>::const_iterator	closest;

	for (;needle != wallet.end(); needle++)
	{
		if (isValidWallet(needle))
		{
			closest = data.find(needle->first);
			if (closest != data.end())
			{
				closest = data.lower_bound(needle->first);
				displayExchange(needle, closest);
			}
			else
			{
				closest = data.lower_bound(needle->first);
				if (closest != data.begin())
					closest--;
				displayExchange(needle, closest);
			}
		}
	}
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

	//	printMap("Printing Data", quentin.getData());
		printMap("Printing Wallet", quentin.getWallet());
	//	exchange(quentin.getData(), quentin.getWallet());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
