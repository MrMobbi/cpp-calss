
#include "harl.hpp"

int	main(int ac, char **av)
{
	harl	test;

	if (ac != 2)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}

	std::string	prompt(av[1]);
	test.complain(prompt);
	return (0);
}
