
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

std::string	safe_getline(std::string line)
{
	std::string	tmp;

	while(1)
	{
		std::cout << line;
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

int main(void)
{
	std::cout << "#####" << std::endl;

	FragTrap	player1("steve");

	std::cout << player1.get_name() << std::endl;
	std::cout << player1.get_ep() << std::endl;
	player1.high_five_guys();
	std::cout << player1.get_ep() << std::endl;
	return (0);
}
