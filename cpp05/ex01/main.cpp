
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include "Bureaucrate.hpp"
#include "Form.hpp"

#define MSG_NAME_BUR "Enter the Name of the bureaucrate : "
#define MSG_GRADE_BUR "Enter the Grade of the Bureaucrate : "
#define MSG_NAME_FORM "Enter Name of the Form : "
#define MSG_SIGN_FORM "Enter the Grade to sign the form : "
#define MSG_EXEC_FORM "Enter the Grade to execute the form : "

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

int	gnl_atoi(std::string line)
{
	std::string	tmp;
	const char	*str;
	int			nb;

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
		//	# Creating Bureaucrate and testing Overload operator
		Bureaucrate	bur1(safe_getline(MSG_NAME_BUR), gnl_atoi(MSG_GRADE_BUR));
		Bureaucrate	bur2(bur1);
		std::cout << bur2 << std::endl;

		//	# Creating Form and testing Overload operator
		Form	form1(safe_getline(MSG_NAME_FORM), gnl_atoi(MSG_SIGN_FORM), gnl_atoi(MSG_EXEC_FORM));
		std::cout << form1 << std::endl;

		std::cout << std::endl;
		std::cout << "### End of Creating class ###" << std::endl;
		std::cout << std::endl;
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
					bur1.gradeUp();
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
				std::cout << "New grade is [" << bur1.getGrade() << "]" << std::endl;
			}
			else if (prompt == "-")
			{
				try
				{
					bur1.gradeDown();
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
				std::cout << "New grade is [" << bur1.getGrade() << "]" << std::endl;
			}
			else if (prompt == "info")
				std::cout << bur1 << std::endl;
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
