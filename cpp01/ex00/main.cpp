
#include <iostream>
#include "Zombie.hpp"

std::string	safe_getline(void)
{
	std::string	prompt;

	std::cout << "Enter a name for your Zombie:" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, prompt);
		if (std::cin.fail() == true)
		{
			std::cout << "Error of the input, closing program!" << std::endl;
			exit (0);
		}
		else if (prompt.length() == 0)
			std::cout << "No blank field please!" << std::endl;
		else if (prompt.length() > 0)
			break ;
	}
	return (prompt);
}

int	main(void)
{
	Zombie	*z = new Zombie(safe_getline());

	z->annonce();
	delete (z);	
	randomChump(safe_getline());
	z = newZombie(safe_getline());
	z->annonce();
	delete (z);
	return (0);
}
