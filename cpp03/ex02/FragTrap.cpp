
#include "FragTrap.hpp"

//	### Constructor ###

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = "Default F";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " has join the battle" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " has join the battle" << std::endl;
}

FragTrap::FragTrap(FragTrap &t)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	std::cout << "FragTrap " << this->_name << " has join the battle" << std::endl;
}

//	### Overload Operator ###

FragTrap	&FragTrap::operator = (const FragTrap &t)
{
	this->_name = t._name;
	this->_hp = t._hp;
	this->_ep = t._ep;
	this->_ad = t._ad;
	std::cout << "FragTrap By the pope an other copy of " << this->_name << std::endl;
	return (*this);
}

//	### Destructor ###

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << this->_name << " have been defeated" << std::endl;
}

//	### Member Function ###

void	FragTrap::high_five_guys(void)
{
	this->_ep--;
	std::cout << "FragTrap " << this->_name << " give you the best high five of history" << std::endl;	
}
