
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "### Construction of test ###" << std::endl;
	const Animal	*meta = new Animal();
	const Animal	*steve = new Cat();
	const Animal	*stuart = new Dog();

	std::cout << std::endl;
	std::cout << "### Testing Function ###" << std::endl;

	meta->make_sound();
	steve->make_sound();
	stuart->make_sound();

	std::cout << "The type of the variable [meta] is -> " << meta->get_type() << std::endl;
	std::cout << "The type of the variable [steve] is -> " << steve->get_type() << std::endl;
	std::cout << "The type of the variable [stuart] is -> " << stuart->get_type() << std::endl;

	std::cout << std::endl << "### Test of Wrong Animal ###" << std::endl;

	const	WrongAnimal	*test1 = new WrongAnimal();
	const	WrongAnimal	*test2 = new WrongCat();

	test1->make_sound();
	test2->make_sound();

	std::cout << "The type of the variable [test1] is -> " << test1->get_type() << std::endl;
	std::cout << "The type of the variable [test2] is -> " << test2->get_type() << std::endl;

	std::cout << std::endl;
	std::cout << "### Destruction of test ###" << std::endl;

	delete(meta);
	delete(steve);
	delete(stuart);
	std::cout << std::endl;
	delete(test1);
	delete(test2);
	return (0);
}
