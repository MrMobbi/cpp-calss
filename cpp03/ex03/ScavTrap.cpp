
#include "ScavTrap.hpp"

//	### Constructor ###

ScavTrap::ScavTrap(void) : ClapTrap(), _default_hp(100), _default_ep(50), _default_ad(20)
{
	this->_name = "Default S";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap " << this->_name << " has join the battle" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _default_hp(100), _default_ep(50), _default_ad(20)
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	std::cout << "ScavTrap " << this->_name << " has join the battle" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &t) : _default_hp(t._default_hp), _default_ep(t._default_ep), _default_ad(t._default_ad)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	std::cout << "ScavTrap " << this->_name << " has join the battle" << std::endl;
}

//	### Overload Operator ###

ScavTrap	&ScavTrap::operator = (const ScavTrap &t)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	this->_default_hp = t._default_hp;
	this->_default_ep = t._default_ep;
	this->_default_ad = t._default_ad;
	std::cout << "ScavTrap By the pope an other copy of " << this->_name << std::endl;
	return (*this);
}

//	### Desctructor ###

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " have been defeated" << std::endl;
}

//	### Member Function ###

void	ScavTrap::attack(const std::string target)
{
	if (this->_ep > 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing "
		<< this->_ad << " points of damages!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "No Energy Points left for ClapTrap "
		<< this->_name << " you can't do shit!" << std::endl;
}

void	ScavTrap::guard_gate(void)
{
	std::cout << "ScavTrap " << this->_name << " is on Gate keeper Mode" << std::endl;
	this->_ep--;
}
