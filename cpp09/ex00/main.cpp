
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

bool	isValidDate(const std::string &date)
{
	struct tm	time;
	char *hugo = strptime(date.c_str(), "%Y-%m-%d", &time);
	int	m = time.tm_mon + 1,
			d = time.tm_mday;

	if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
			return (false);
	else if (d > 29 && m == 2)
		return (false);
	else if (hugo && hugo[0] == 0)
		return (true);
	else
		return (false);
	return (true);
}

template<typename t_iter>
bool	isValidWallet(t_iter &needle)
{
	if (std::atoi(needle->second.c_str()) < 0)
	{
		std::cout << "Error: Not a positive number : " << needle->second << std::endl;
		return (false);
	}
	else if (std::atoi(needle->second.c_str()) > 9999)
	{
		std::cout << "Error: Too large number : " << needle->second << std::endl;
		return (false);
	}
	else if (needle->second.find_first_not_of("0123456789.") != std::string::npos)
	{
		std::cout << "Error: Not a number : " << needle->second << std::endl;
		return (false);
	}
	if (!isValidDate(needle->first))
	{
		std::cout << "Error: Bad input : " << needle->first << std::endl;
		return (false);
	}
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

		printMap("Printing Data", quentin.getData());
		printMap("Printing Wallet", quentin.getWallet());
		exchange(quentin.getData(), quentin.getWallet());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
