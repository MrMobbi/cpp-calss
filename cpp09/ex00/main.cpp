
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

bool	files(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wring number of arguments" << std::endl;
		return (false);
	}
	info.data.open("data.csv");
	if (!info.data.is_open())
	{
		std::cout << "Data file can't be opened" << std::endl;
		return (false);
	}
	std::string	input(av[1]);
	info.wallet.open((input.c_str()));
	if (!info.wallet.is_open())
	{
		std::cout << "Wallet file can't be opened" << std::endl;
		return (false);
	}
	return (true);
}

bool	pars(t_info &info, std::map<std::string, int> &data, std::map<std::string, int> &wallet)
{
	std::string	pars;
	std::string	key;

	while (info.data
	return (true);
}

void print_map(std::string comment, const std::map<std::string, int>& m)
{
    std::cout << comment;

	for (std::map<std::string, int>::const_iterator it = m.begin(); it != m.end(); it++)
		std::cout << it->first << " = " << it->second << "; ";
	 std::cout << '\n';
}

int	main(int	ac, char **av)
{
	BitcoinExchange	quentin;

	if (!files(ac, av, info))
		return (1);
	if(!pars(info))
		return (2);
	
	ref["1)"] = 1;
	print_map("key :\n", ref);
	info.data.close();
	info.wallet.close();
	return (0);
}
