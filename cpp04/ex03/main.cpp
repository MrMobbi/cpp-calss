
#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main(void)
{
	AMateria	*i = new Ice();
	AMateria	*c = new Cure();
	ICharacter	*me = new Character("jean");

	std::cout << i->get_type() << std::endl;
	std::cout << c->get_type() << std::endl;

	AMateria	*c_c = c->clone();
	AMateria	*i_c = i->clone();

	std::cout << c_c->get_type() << std::endl;
	std::cout << i_c->get_type() << std::endl;

	delete(i);
	delete(c);
	delete(c_c);
	delete(i_c);
	return (0);
}
