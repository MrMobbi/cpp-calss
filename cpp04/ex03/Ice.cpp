
#include "Ice.hpp"

//	### Constructor ###

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(const Ice &t) : AMateria(t) {}

//	### Overload Operator ###

Ice &Ice::operator = (const Ice &t)
{
	this->_type = t._type;
	std::cout << "Copy assignement operator of Ice called" << std::endl;
	return (*this);
}

//	### Destructor ###

Ice::~Ice(void) {}

//	### Member Function ###

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "*shoots an ice bolt at " << target.get_name() << " *" << std::endl;	
}
