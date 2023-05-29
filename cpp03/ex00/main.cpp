
#include "ClapTrap.hpp"

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

int	action(ClapTrap &player1, ClapTrap &player2)
{
	std::string	command;
	while (1)
	{
		command = safe_getline("%> ");
		if (command == "attack")
		{
			player2.attack(player1.get_name());
			player1.take_damage(0);
			break ;
		}
		else if (command == "repair")
		{
			player2.be_repaired(1);
			break ;
		}
		else
			std::cout << "Action non valid" << std::endl;
	}
	return (player2.get_ep());
}

void	start(ClapTrap &player1, ClapTrap &player2)
{
	(void) player2;
	std::cout << player1.get_name() <<  " has challenging you in a battle!" << std::endl;
	std::cout << "To win this battle you have 2 actions you can make!" << std::endl;
	std::cout << "[attack] deal damage equal to your force" << std::endl;
	std::cout << "[repair] heal your hp by 1" << std::endl;
	std::cout << "Each action need 1 Energy Point,";
	std::cout << " you curently have 10" << std::endl;
	while (1)
	{
		if (action(player1, player2) == 0)
			break;
		player1.attack(player2.get_name());
		if (player1.get_ep()  > 0)
			player2.take_damage(0);
		player1.attack(player2.get_name());
		if (player1.get_ep()  > 0)
			player2.take_damage(0);
		std::cout << "Energy Point left [" << player2.get_ep() << "]" << std::endl;
	}
}

int main(void)
{
	std::cout << "#####" << std::endl;
	ClapTrap	player1;

	std::cout << std::endl;
	std::cout << "Hello compagnon, What's is your name?" << std::endl;

	ClapTrap	player2(safe_getline("%> "));
	
	start(player1, player2);
	return (0);
}
