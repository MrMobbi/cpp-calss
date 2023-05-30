
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

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

	std::cout << "Default Constructor :" << std::endl;
	DiamondTrap	player0;
	std::cout << std::endl << "Name Constructor :" << std::endl;
	DiamondTrap	player1("jean micheng");
	std::cout << std::endl << "Copy Constructor :" << std::endl;
	DiamondTrap	player2(player1);
	
	std::cout << std::endl;

	player1.attack("truc");
	player1.take_damage(10);
	player1.be_repaired(2);
	player1.high_five_guys();
	player1.guard_gate();
	player1.guard_gate();
	player1.who_am_i();

	std::cout << std::endl;

	std::cout << std::endl << "Copy Assingment :" << std::endl;
	player0 = player1;
	player0.who_am_i();

	std::cout << std::endl;

	return (0);
}
