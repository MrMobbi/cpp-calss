
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

std::string	safe_getline(std::string line)
{
	std::string	tmp;

	while (1)
	{
		std::cout << line;
		std::getline(std::cin, tmp);
		if (std::cin.fail() == true)
		{
			std::cout << "Error of the input closing program!" << std::endl;
			exit(0);
		}
		else if (tmp.length() == 0)
			std::cout << "Field can't be blank !!" << std::endl;
		else if (tmp.length() > 0)
			break ;
	}
	return (tmp);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	if (std::atoi(av[1]) < 0)
		return (0);
	std::cout << std::endl;
	std::cout << "### Construction of test ###" << std::endl;

//	AAnimal	*pouic = new AAnimal();
	AAnimal	*test[std::atoi(av[1])];

	for (int i = 0; i < std::atoi(av[1]); i++)
	{
		if (i % 2 == 1)
			test[i] = new Dog();
		else
			test[i] = new Cat();
	}

	std::cout << std::endl;
	std::cout << "### Testing Type and sound###" << std::endl;

	for (int i = 0; i < std::atoi(av[1]); i++)
			test[i]->make_sound();

	for (int i = 0; i < std::atoi(av[1]); i++)
		std::cout << "The type of the variable [test[" << i <<"]] is -> " << test[i]->get_type() << std::endl;

	std::cout << std::endl;
	std::cout << "### Destruction of test ###" << std::endl;

	for (int i = 0; i < std::atoi(av[1]); i++)
		delete (test[i]);
	return (0);
}
