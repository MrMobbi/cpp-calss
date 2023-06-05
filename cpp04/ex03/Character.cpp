
#include "Character.hpp"

//	### Constructor ###

Character::Character(void) : _name("pouic") 
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character &t) : _name(t._name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = t._inventory[i];
}

//	### Overload Operator ###

Character &Character::operator = (const Character &t)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = t._inventory[i];
	this->_name = t._name;
	return (*this);
}

//	### Destructor ###

Character::~Character(void) 
{
	for (int i = 0; i < 4; i++)
		this->unequip(i);
}

//	### Member Function ###

std::string const	&Character::get_name(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	int	i = 0;
	while (i < 4 && this->_inventory[i] != NULL)
		i++;
	if (i == 4)
	{
		std::cout << "Inventory is Full!!" << std::endl;
		return ;
	}
	if (!m)
	{
		std::cout << "Materia is not valid" << std::endl;
	}
	this->_inventory[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Wrong index!" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Wrong index!" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
