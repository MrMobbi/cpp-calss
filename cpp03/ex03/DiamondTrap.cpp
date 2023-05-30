
#include "DiamondTrap.hpp"

//	### Constructor ###

DiamondTrap::DiamondTrap(void) : ClapTrap()
{
	this->_hp = FragTrap::_default_hp;
	this->_ep = ScavTrap::_default_ep;
	this->_ad = FragTrap::_default_ad;
	this->_name = "Default D";
	ClapTrap::_name = this->_name + "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " has join the battle!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name), _name(name)
{
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hp = FragTrap::_default_hp;
	this->_ep = ScavTrap::_default_ep;
	this->_ad = FragTrap::_default_ad;
	std::cout << "DiamondTrap " << this->_name << " has join the battle!" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &t)
{
	this->_name = t._name;
	ClapTrap::_name = t._name + "clap_name";
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	std::cout << "DiamondTrap " << this->_name << " has join the battle" << std::endl;
}

//	### Overload Operator ###

DiamondTrap	&DiamondTrap::operator = (const DiamondTrap &t)
{
	this->_name = t._name;
	ClapTrap::_name = t._name + "_clap_name";
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	std::cout << "DiamondTrap By the pope an other copy of " << this->_name << std::endl;
	return (*this);
}

//	### Desctructor ###

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << this->_name << " have been defeated" << std::endl;
}

//	### Member Function ###

void	DiamondTrap::who_am_i(void) const
{
	std::cout << "### Stats of Diamond Trap ###" << std::endl;
	std::cout << "ClapTrap name : " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap name : " << this->_name << std::endl;
	std::cout << "DiamondTrap Hit Point : " << this->_hp << std::endl;
	std::cout << "DiamondTrap Energy Point : " << this->_ep << std::endl;
	std::cout << "DiamondTrap Attack Damage : " << this->_ad << std::endl;
}

void	DiamondTrap::attack(std::string target)
{
	ScavTrap::attack(target);
}
