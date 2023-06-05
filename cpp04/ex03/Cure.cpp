
#include "Cure.hpp"

//	### Constructor ###

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure &t) : AMateria(t) {}

//	### Overload Operator ###

Cure &Cure::operator = (const Cure &t)
{
	this->_type = t._type;
	std::cout << "Copy assignement operator of Cure called" << std::endl;
	return (*this);
}

//	### Destructor ###

Cure::~Cure(void) {}

//	### Member Function ###

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heal " << target.get_name() << "'s wounds *" << std::endl;
}
