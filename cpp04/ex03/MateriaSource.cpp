
#include "MateriaSource.hpp"

//	### Constructor ###

MateriaSource::MateriaSource(void)
{
	std::cout << "Constructor of MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &t)
{
	(void) t;
	std::cout << "Copy constructor of MateriaSource called" << std::endl;
}

//	### Overload Operator ###

MateriaSource &MateriaSource::operator = (const MateriaSource &t)
{
	(void) t;
	std::cout << "Copy assignement operator of MateriaSource called" << std::endl;
	return (*this);
}

//	### Destructor ###

MateriaSource::~MateriaSource(void)
{
	std::cout << "Destructor of MateriaSource called" << std::endl;
}

//	### Member Function ###

