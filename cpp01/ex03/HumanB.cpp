
#include "HumanB.hpp"

void	HumanB::attack(void) const
{
	std::cout << this->_name << "attack with their " << this->_weapon->get_type() << std::endl;
}

void	HumanB::set_weapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

HumanB::HumanB(void)
{
	std::cout << "HumanA have join the batle with no weapon and no name!" << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	std::cout << this->_name <<" have join the batle with no weapon"<< std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << this->_name << " is dead in a lot of pain!" << std::endl;
}
