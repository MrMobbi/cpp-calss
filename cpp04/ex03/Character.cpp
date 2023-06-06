
#include "Character.hpp"

//	### Constructor ###

Character::Character(void) : _name("pouic"), _lost(NULL) 
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name), _lost(NULL)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character &t) : _name(t._name), _lost(NULL)
{
	for (int i = 0; i < 4; i++)
	{
		if (t._inventory[i] != NULL)
			this->_inventory[i] = t._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
}

//	### Overload Operator ###

Character &Character::operator = (const Character &t)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
		this->_inventory[i] = t._inventory[i]->clone();
	}
	this->_name = t._name;
	return (*this);
}

//	### Destructor ###

Character::~Character(void) 
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete (this->_inventory[i]);
		this->_inventory[i] = NULL;
	}
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
		return ;
	}
	this->_inventory[i] = m->clone();
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Wrong index!" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "This emplacement is empty!" << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL)
		this->_lost = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << "Wrong index!" << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "This emplacement is empty!" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

void	Character::handle_lost(void)
{
	delete (this->_lost);
}

void	Character::show_inventory(void) const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			std::cout << "Slot [" << i + 1 << "] is : " << this->_inventory[i]->get_type() << std::endl;
	}
}
