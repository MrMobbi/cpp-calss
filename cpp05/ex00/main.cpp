
#include <iostream>
#include <cstdlib>
#include <string>
#include "Bureaucrate.hpp"

std::string	safe_getline(void)
{
	std::string	tmp;

	std::cout << "Enter the Name of the bureaucrate." << std::endl;
	while (1)
	{
		std::getline(std::cin, tmp);
		if (std::cin.fail() == true)
		{
			std::cout << "Error of the input, closing program!" << std::endl;
			exit(0);
		}
		else if (tmp.length() == 0)
			std::cout << "Field can't be blank !!" << std::endl;
		else if (tmp.length() > 0)
			break ;
	}
	return (tmp);
}

int	safe_getline_atoi(void)
{
	std::string	tmp;
	const char	*str;
	int			nb;

	std::cout << "Enter the grade of the bureaucrate." << std::endl;
	while (1)
	{
		std::getline(std::cin, tmp);
		if (std::cin.fail() == true)
		{
			std::cout << "Error of the input, closing program!" << std::endl;
			exit(0);
		}
		else if (tmp.length() == 0)
			std::cout << "Field can't be blank !!" << std::endl;
		else if (tmp.length() > 0)
			break ;
	}
	str = const_cast<const char *>(tmp.c_str());
	nb = std::atoi(str);
	return (nb);
}

int	main(int ac, char **av)
{
	(void) av;
	if (ac != 1)
	{
		std::cout << "Please run the programe with no arguments" << std::endl;
		return (0);
	}

	Bureaucrate	gile(safe_getline(), safe_getline_atoi());
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Bureaucrate Name : " << gile.getName();
	std::cout << ", Bureaucrate Rank : " << gile.getGrade() << std::endl;
	return (0);
}
