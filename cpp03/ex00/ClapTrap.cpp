
#include "ClapTrap.hpp"

//	### Constructor ###

ClapTrap::ClapTrap(void) : _name("Arthur King of Britain"), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << this->_name << " has join the battle!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _ad(0)
{
	std::cout << "ClapTrap " << this->_name << " has join the battle!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &t) : _name(t._name), _hp(t._hp), _ep(t._ep), _ad(t._ad)
{
	std::cout << "ClapTrap What a copy of " << this->_name << std::endl;
}

//	### Overload Operator ###

ClapTrap	&ClapTrap::operator = (const ClapTrap &t)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	std::cout << "ClapTrap By the pope an other copy of " << this->_name << std::endl;
	return (*this);
}

//	### Desctructor ###

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " have been defeated" << std::endl;
}

//	### Member Function ###

void	ClapTrap::attack(const std::string target)
{
	if (this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing "
		<< this->_ad << " points of damages!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "No Energy Points left for ClapTrap "
		<< this->_name << " you can't do shit!" << std::endl;
}

void	ClapTrap::take_damage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " have take " 
	<< amount << " of damage!" << std::endl;
	this->_hp -= amount;
}

void	ClapTrap::be_repaired(unsigned int amount)
{
	if (this->_ep > 0)
	{
		std::cout << "ClapTrap " << this->_name << "have been repaied of " << amount
		<< " points!" << std::endl;
		this->_hp += amount;
		this->_ep--;
	}
	else
		std::cout << "No Energy Points left you can't do shit!" << std::endl;
}

std::string	ClapTrap::get_name(void) const
{
	return (this->_name);
}

int	ClapTrap::get_ep(void) const
{
	return (this->_ep);
}
