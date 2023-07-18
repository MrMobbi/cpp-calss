
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define MSG_NAME_BUR "Enter the Name of the bureaucrate : "
#define MSG_GRADE_BUR "Enter the Grade of the Bureaucrat : "
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
		std::cout << std::endl;
		std::cout << "### Creating class ###" << std::endl;
		std::cout << std::endl;
		//	# Creating Bureaucrat and testing Overload operator
		Bureaucrat	bur1(safe_getline(MSG_NAME_BUR), gnl_atoi(MSG_GRADE_BUR));
		Bureaucrat	bur2(bur1);
		std::cout << bur2 << std::endl;

		//	# Creating Form and testing Overload operator
		Form	form1(safe_getline(MSG_NAME_FORM), gnl_atoi(MSG_SIGN_FORM), gnl_atoi(MSG_EXEC_FORM));
		Form	form2(form1);
		std::cout << form2 << std::endl;

		std::cout << std::endl;
		std::cout << "### Starting test of Bureaucrat function ###" << std::endl;
		std::cout << std::endl;
		std::cout << "Type '+' or '-' to move the grade of the bureaucrat" << std::endl;
		std::cout << "Type 'sign' for the Bureaucrat to sign the Form" << std::endl;
		std::cout << "Type 'signed' to see if the Bureaucrat have sign the Form" << std::endl;
		std::cout << "Type 'info b' to get all data of bureaucrat" << std::endl;
		std::cout << "Type 'info f' to get all data of Form" << std::endl;
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
			else if (prompt == "sign")
			{
				try
				{
					form1.beSigned(&bur1);
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			else if (prompt == "signed")
				form1.signForm();
			else if (prompt == "info b")
				std::cout << bur1 << std::endl;
			else if (prompt == "info f")
					std::cout << form1;
			else if (prompt == "exit")
				break;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
