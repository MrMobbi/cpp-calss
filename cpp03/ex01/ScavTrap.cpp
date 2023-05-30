
#include "ScavTrap.hpp"

//	### Constructor ###

ScavTrap::ScavTrap(void) : ClapTrap() 
{
	this->_name = "Default S";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	this->_guard_mode = false;
	std::cout << "ScavTrap " << this->_name << " has join the battle" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) 
{
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	this->_guard_mode = false;
	std::cout << "ScavTrap " << this->_name << " has join the battle" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &t)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	this->_guard_mode = t._guard_mode;
	std::cout << "ScavTrap " << this->_name << " has join the battle" << std::endl;
}

//	### Overload Operator ###

ScavTrap	&ScavTrap::operator = (const ScavTrap &t)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	this->_guard_mode = t._guard_mode;
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
	if (this->_guard_mode == false)
	{
		std::cout << "ScavTrap " << this->_name << " is on Gate keeper Mode" << std::endl;
		this->_guard_mode = true;
		this->_ep--;
	}
	else
		std::cout << "ScavTrap " << this->_name << " is alredy on Gate keeper Mode" << std::endl;
}

void	ScavTrap::show_stat(void) const
{
	std::cout << "SvacTrap name : " << this->_name << std::endl;
	std::cout << "SvacTrap Hit Point : " << this->_hp << std::endl;
	std::cout << "SvacTrap Energy Point : " << this->_ep << std::endl;
	std::cout << "SvacTrap Attack damage : " << this->_ad << std::endl;
}
