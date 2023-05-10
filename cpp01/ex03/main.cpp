
#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon	club("sharp club");
	HumanA	bob("bob", club);
	HumanB	jim("jim");
	
	std::cout << std::endl;
	std::cout << "test :" << std::endl;
	bob.attack();
	club.set_type("not a sharp club");
	bob.attack();
	jim.set_weapon(club);
	jim.attack();
	club.set_type("a sharp club again");
	jim.attack();
	club.set_type("maybe not a sharp club this time");
	jim.attack();
	std::cout << "end of test :" << std::endl;
	std::cout << std::endl;
	return (0);
}
