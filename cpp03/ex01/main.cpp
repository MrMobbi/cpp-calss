
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
	ScavTrap	player1("steve");

	std::cout << player1.get_name() << std::endl;

	player1.attack("truc");
	std::cout << player1.get_ep() << std::endl;
	player1.guard_gate();
	std::cout << player1.get_ep() << std::endl;
	player1.guard_gate();
	std::cout << player1.get_ep() << std::endl;
	player1.take_damage(0);
	std::cout << player1.get_ep() << std::endl;
	player1.be_repaired(1);
	std::cout << player1.get_ep() << std::endl;
	player1.show_stat();
	return (0);
}
