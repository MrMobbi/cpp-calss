
#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define MSG_NAME_BUR "Enter the Name of the bureaucrate : "
#define MSG_GRADE_BUR "Enter the Grade of the Bureaucrat : "
#define MSG_NAMESH_FORM "Enter Name of the Shrubbery Form : "
#define MSG_NAMERO_FORM "Enter Name of the Robotomy Form : "
#define MSG_NAMEPR_FORM "Enter Name of the Presidnetial Pardon Form : "
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

		//	# Creating AForm and testing Overload operator
		ShrubberyCreationForm	f1(safe_getline(MSG_NAMESH_FORM));
		ShrubberyCreationForm	f2(f1);
		std::cout << f2 << std::endl;

		RobotomyRequestForm		f3(safe_getline(MSG_NAMERO_FORM));
		RobotomyRequestForm		f4(f3);
		std::cout << f4 << std::endl;

		PresidentialPardonForm	f5(safe_getline(MSG_NAMEPR_FORM));
		PresidentialPardonForm	f6(f5);
		std::cout << f6 << std::endl;

		std::cout << std::endl;
		std::cout << "### Starting test of Bureaucrat and AForm function ###" << std::endl;
		std::cout << std::endl;
		std::cout << "Type '+' or '-' to move the grade of the bureaucrat" << std::endl;
		std::cout << "Type 're grade' to change the grade of the Bureaucrat" << std::endl;
		std::cout << "Type 'sign' or 'execute' for the Bureaucrat to sign or execute the Form" << std::endl;
		std::cout << "When in sign or execute type one of the 3 Form to sign it :" << std::endl;
		std::cout << "- '1' for 'Shrubbery'" << std::endl;
		std::cout << "- '2' for 'Robotomy'" << std::endl;
		std::cout << "- '3' for 'President'" << std::endl;
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
				while (1)
				{
					std::cout << "Enter the type of the Form you want to sign" << std::endl;
					prompt = safe_getline("$> ");
					if (prompt == "1")
						bur1.signForm(f1);
					else if (prompt == "2")
						bur1.signForm(f3);
					else if (prompt == "3")
						bur1.signForm(f5);
					break ;
				}
			}
			else if (prompt == "execute")
			{
				while (1)
				{
					std::cout << "Enter the type of the Form you want to execute" << std::endl;
					prompt = safe_getline("$> ");
					if (prompt == "1")
						bur1.executeForm(f1);
					else if (prompt == "2")
						bur1.executeForm(f3);
					else if (prompt == "3")
						bur1.executeForm(f5);
					break ;
				}
			}
			else if (prompt == "info b")
				std::cout << bur1 << std::endl;
			else if (prompt == "info f")
			{
				while (1)
				{
					std::cout << "Enter the type of the Form for the info you want" << std::endl;
					prompt = safe_getline("$> ");
					if (prompt == "1")
					{
						std::cout << f1 << std::endl;
						break;
					}
					else if (prompt == "2")
					{
						std::cout << f3 << std::endl;
						break ;
					}
					else if (prompt == "3")
					{
						std::cout << f5 << std::endl;
						break ;
					}
					else if (prompt == "exit")
						break ;
				}
			}
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
