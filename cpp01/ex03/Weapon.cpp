
#include "Weapon.hpp"

std::string	Weapon::get_type(void) const
{
	return (this->_type);
}

void	Weapon::set_type(std::string new_type)
{
	this->_type = new_type;
}

Weapon::Weapon(void)
{
	this->_type = "";
	std::cout << "Weapon with no type have been created" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
	std::cout << "Weapon type : " << this->_type << " have been created" << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon have been lost or destroyed" << std::endl;
}
