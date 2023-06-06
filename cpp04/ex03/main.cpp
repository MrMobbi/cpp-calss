
#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "### My own Example ###" << std::endl << std::endl;

	std::cout << "### Test of Materia ###" << std::endl << std::endl;

	MateriaSource	*src = new MateriaSource();
	src->learn_materia(new Ice());
	src->learn_materia(new Cure());
	std::cout << std::endl;
	std::cout << "src Materia ->" << std::endl;
	src->show_stock();
	src->learn_materia(new Ice());
	src->learn_materia(new Cure());
	src->learn_materia(new Cure());
	std::cout << std::endl;
	std::cout << "src Materia ->" << std::endl;
	src->show_stock();

	std::cout << std::endl;
	MateriaSource	*src2 = new MateriaSource(*src);
	std::cout << "src2 Materia (copy constructor) ->" << std::endl;
	src2->show_stock();

	std::cout << std::endl;
	MateriaSource	*src3;
	src3 = new MateriaSource(*src);
	std::cout << "src3 Materia (overlaod operator) ->" << std::endl;
	src3->show_stock();

	delete (src2);
	delete (src3);

	std::cout << std::endl << "### Test of Character ###" << std::endl << std::endl;

	Character	*player1 = new Character("Jean Mi-Cheng");

	std::cout << "Name of Player1 : " << player1->get_name() << std::endl;

	AMateria	*tmp1;
	tmp1 = src->create_materia("ice");
	player1->equip(tmp1);
	player1->equip(tmp1);
	free(tmp1);
	tmp1 = src->create_materia("cure");
	player1->equip(tmp1);
	player1->equip(tmp1);
	free(tmp1);
	tmp1 = src->create_materia("fire");
	player1->equip(tmp1);
	player1->equip(tmp1);
	std::cout << std::endl;
	std::cout << "player1 inventory ->" << std::endl;
	player1->show_inventory();
	std::cout << std::endl << "### unequip test ###" << std::endl << std::endl;
	player1->unequip(0);
	player1->unequip(0);
	player1->handle_lost();
	player1->unequip(9);
	player1->show_inventory();

	std::cout << std::endl;
	Character	*player2 = new Character(*player1);
	std::cout << "Name of Player2 : " << player1->get_name() << std::endl;
	player2->show_inventory();

	std::cout << std::endl;
	Character	*player3;
	std::cout << "Name of Player3 : " << player1->get_name() << std::endl;
	player3 = new Character(*player2);
	player2->show_inventory();

//	Wrong contructor
//	Character	player4;

	std::cout << std::endl;
	Character	billy("billy");
	player1->use(0, billy);
	player1->use(1, billy);
	player1->use(2, billy);
	player1->use(3, billy);

	delete (player1);
	delete (player2);
	delete (player3);
	delete (src);

	std::cout << std::endl;
	std::cout << "### Example of Subject ###" << std::endl << std::endl;

	IMateriaSource* s_src = new MateriaSource();
	s_src->learn_materia(new Ice());
	s_src->learn_materia(new Cure());

	ICharacter* s_me = new Character("me");

	AMateria* tmp;
	tmp = s_src->create_materia("ice");
	s_me->equip(tmp);
	free(tmp);
	tmp = s_src->create_materia("cure");
	s_me->equip(tmp);
	free(tmp);

	ICharacter* s_bob = new Character("bob");

	s_me->use(0, *s_bob);
	s_me->use(1, *s_bob);

	delete s_bob;
	delete s_me;
	delete s_src;

	std::cout << std::endl << "### END ###" << std::endl << std::endl;

	return (0);
}
