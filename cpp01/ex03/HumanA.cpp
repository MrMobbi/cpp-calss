
#include "HumanA.hpp"

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attack with their " << this->_weapon.get_type() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name)
{
	std::cout << this->_name <<" have join the batle with " << this->_weapon.get_type() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << this->_name << " is dead in a lot of pain!" << std::endl;
}
