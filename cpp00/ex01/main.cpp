
#include "main.hpp"

void	print_command(void)
{
	std::cout << std::endl;
//	Explaination of the command ADD
	std::cout << "Command ADD :" << std::endl;
	std::cout << "- Create a new conctact and the prompt will ask ";
	std::cout << "you to put the informations of the contact" << std::endl;
	std::cout << "- The informations of the contact are :" << std::endl;
	std::cout << "	- First Name" << std::endl;
	std::cout << "	- Last Name" << std::endl;
	std::cout << "	- Nickcname" << std::endl;
	std::cout << "	- Phone Number" << std::endl;
	std::cout << "	- Darkest Secret" << std::endl;
	std::cout << std::endl;
//	Explaination of the command SEARCH
	std::cout << "Command SEARCH :" << std::endl;
	std::cout << "- Will display your contacts in 4 columns like the ";
	std::cout << "example below ->" << std::endl;
	std::cout << " [index|First Name|Last Name|Nickname]" << std::endl;
	std::cout << "- Then the prompt ask you the index of the contact you want ";
	std::cout << "to see all the infos" << std::endl;
	std::cout << std::endl;
//	Explaination of the command EXIT
	std::cout << "Command EXIT :" << std::endl;
	std::cout << "- Exit the program and all your contact will be ";
	std::cout << "lost forever" << std::endl;
	std::cout << std::endl;
}

int	parse_prompt(std::string prompt)
{
	char	*str = const_cast<char *>(prompt.c_str());
	for (size_t i = 0; i < std::strlen(str); i++)
		str[i] = std::tolower(str[i]);
	std::string	command(str);
	if (command == "add")
		return (E_ADD);
	else if (command == "search")
		return (E_SEARCH);
	else if (command == "exit")
		return (E_EXIT);
	else if (command == "help")
		print_command();
	else
		std::cout << "Command non valid, type HELP to see them" << std::endl;
	return (0);
}

void	starting_program(void)
{
	std::cout << "Hello and welcome in to the best PhoneBook in the world!" << std::endl;
	std::cout << "Here is the list of command available :" << std::endl;
	std::cout << "ADD : create a new contact (only 8 available)" << std::endl;
	std::cout << "SEARCH : show all the contact and some cool function" << std::endl;
	std::cout << "EXIT : quit the PhoneBook (all contact will be lost)" << std::endl;
	std::cout << "HELP : all commands explained" << std::endl;
}

int	main(void)
{
	PhoneBook	phone;
	std::string	prompt;

	std::cout << std::endl;
	starting_program();
	while (1)
	{
		std::cout << "$> : ";
		std::getline(std::cin, prompt);
		if (std::cin.fail() == true)
			break ;
		if (parse_prompt(prompt) == E_EXIT)
			break ;
	}
	std::cout << std::endl;
	return (0);
}
