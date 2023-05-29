
#include "FragTrap.hpp"

//	### Constructor ###

FragTrap::FragTrap(void) : ClapTrap(), _default_hp(100), _default_ep(100), _default_ad(30)
{
	this->_name = "Default F";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " has join the battle" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name), _default_hp(100), _default_ep(100), _default_ad(30)
{
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "FragTrap " << this->_name << " has join the battle" << std::endl;
}

FragTrap::FragTrap(FragTrap &t) : _default_hp(t._default_hp), _default_ep(t._default_ep), _default_ad(t._default_ad)
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
	this->_default_hp = t._default_hp;
	this->_default_ep = t._default_ep;
	this->_default_ad = t._default_ad;
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
