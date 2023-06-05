
#include "AMateria.hpp"

//	### Constructor ###

AMateria::AMateria(void) : _type("M") {}

AMateria::AMateria(const std::string &type) : _type(type) {}

AMateria::AMateria(const AMateria &t) : _type(t._type) {}

//	### Overload Operator ###

AMateria &AMateria::operator = (const AMateria &t)
{
	this->_type = t._type;
	return (*this);
}

//	### Destructor ###

AMateria::~AMateria(void) {}

//	### Member Function ###

std::string	const &AMateria::get_type(void) const
{
	return (this->_type);
}

void		AMateria::use(ICharacter &target)
{
	(void) target;
}
