
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

//	### Constructor ###

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_stock[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &t)
{
	for (int i = 0; i < 4; i++)
	{
		if (t._stock[i] != NULL)
			this->_stock[i] = t._stock[i]->clone();
		else
			this->_stock[i] = t._stock[i];
	}
}

//	### Overload Operator ###

MateriaSource &MateriaSource::operator = (const MateriaSource &t)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_stock[i] != NULL)
			delete (this->_stock[i]);
		if (t._stock[i] != NULL)
			this->_stock[i] = t._stock[i]->clone();
		else
			this->_stock[i] = NULL;
	}
	return (*this);
}

//	### Destructor ###

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_stock[i] != NULL)
			delete (this->_stock[i]);
		this->_stock[i] = NULL;
	}
}

//	### Member Function ###

void	MateriaSource::learn_materia(AMateria *m)
{
	int	check = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->_stock[i] == NULL)
		{
			this->_stock[i] = m->clone();
			check++;
			break ;
		}
	}	
	if (check == 0)
		std::cout << "Stock is Full" << std::endl;
	delete (m);
}

AMateria	*MateriaSource::create_materia(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_stock[i]->get_type() == type)
			return (this->_stock[i]->clone());
	}
	std::cout << "Materia not found" << std::endl;
	return (NULL);
}

void	MateriaSource::show_stock(void) const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_stock[i] != NULL)
			std::cout << "Slot [" << i + 1 << "] is : " << this->_stock[i]->get_type() << std::endl;
	}
}
