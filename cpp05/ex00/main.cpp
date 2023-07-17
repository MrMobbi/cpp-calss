
#include <iostream>
#include <cstdlib>
#include <string>
#include "Bureaucrate.hpp"

std::string	safe_getline(std::string line)
{
	std::string	tmp;

	std::cout << line;
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

	std::cout << "Enter the grade of the bureaucrate :";
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

	try
	{
		Bureaucrate	gile(safe_getline("Enter the Name of the bureaucrate :"), safe_getline_atoi());
		Bureaucrate	robert(gile);
	
		std::cout << robert << std::endl;
		std::cout << "Type '+' or '-' to move the grade of the bureaucrate" << std::endl;
		std::cout << "Type 'info' to get the rank of the bureaucrate" << std::endl;
		std::cout << "Type 'exit' to quit" << std::endl;
	
		std::string	prompt;
		while (1)
		{
			prompt = safe_getline("$> ");
			if (prompt == "+")
			{
				try
				{
					gile.gradeUp();
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
				std::cout << "New grade is [" << gile.getGrade() << "]" << std::endl;
			}
			else if (prompt == "-")
			{
				try
				{
					gile.gradeDown();
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
				std::cout << "New grade is [" << gile.getGrade() << "]" << std::endl;
			}
			else if (prompt == "info")
				std::cout << gile << std::endl;
			else if (prompt == "exit")
				break ;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
