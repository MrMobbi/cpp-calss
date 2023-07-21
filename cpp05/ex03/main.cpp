
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define MSG_NAME_BUR "Enter the Name of the bureaucrate : "
#define MSG_GRADE_BUR "Enter the Grade of the Bureaucrat : "
#define MSG_TARGET_FORM "Enter Name of the Form : "
#define MSG_NAME_FORM "Enter the type of the Form you want to create : "

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

void	print_help(void)
{
	std::cout << std::endl;
	std::cout << "### Starting test of Bureaucrat and AForm function ###" << std::endl;
	std::cout << std::endl;
	std::cout << "Type 'help' to see all the command" << std::endl;
	std::cout << "Type '+' or '-' to move the grade of the bureaucrat" << std::endl;
	std::cout << "Type 're grade' to change the grade of the Bureaucrat" << std::endl;
	std::cout << "Type 'sign' or 'execute' for the Bureaucrat to sign or execute the Form" << std::endl;
	std::cout << "Type 'create' for the intern to create a Form" << std::endl;
	std::cout << "Type 'info b' to get all data of bureaucrat" << std::endl;
	std::cout << "Type 'info f' to get all data of Form" << std::endl;
	std::cout << "Type 'exit' to quit" << std::endl;
}

void	help_creation(void)
{
	std::cout << "1 for Shrubbery Creation" << std::endl;
	std::cout << "2 for Robotomy Request" << std::endl;
	std::cout << "3 for Presidential Pardon" << std::endl;
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

		AForm	*form = NULL;
		Intern	bitch;

		print_help();

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
			else if (prompt == "re grade")
			{
				try
				{
					bur1.reGrade(gnl_atoi(MSG_GRADE_BUR));
				}
				catch (std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			else if (prompt == "sign")
			{
				if (form != NULL)
					bur1.signForm(*form);
				else
					std::cout << "No Form given" << std::endl;
			}
			else if (prompt == "execute")
			{
				if (form != NULL)
					bur1.executeForm(*form);
				else
					std::cout << "No Form given" << std::endl;
			}
			else if (prompt == "info b")
				std::cout << bur1 << std::endl;
			else if (prompt == "info f")
				std::cout << form << std::endl;
			else if (prompt == "create")
			{
				if (form != NULL)
					delete(form);
				help_creation();
				prompt = safe_getline("$> ");
				if (prompt == "1")
					form = bitch.makeForm("shrubbery creation", safe_getline(MSG_TARGET_FORM));
				if (prompt == "2")
					form = bitch.makeForm("robotomy request", safe_getline(MSG_TARGET_FORM));
				if (prompt == "3")
					form = bitch.makeForm("presidential pardon", safe_getline(MSG_TARGET_FORM));

			}
			else if (prompt == "help")
				print_help();
			else if (prompt == "exit")
			{
				if (form != NULL)
					delete(form);
				break;
			}
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
