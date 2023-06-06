
#include "WrongAnimal.hpp"

//	### Constructor ###

WrongAnimal::WrongAnimal(void) : _type("None")
{
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &t) : _type(t._type)
{
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
}

//	### Overload Operator ###

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &t)
{
	this->_type = t._type;
	std::cout << "Copy assignement operator of WrongAnimal called" << std::endl;
	return (*this);
}

//	### Destructor ###

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

//	### Member Function ###

void	WrongAnimal::make_sound(void) const
{
	std::cout << "*Wrong Inaudible sound*" << std::endl;
}

std::string	WrongAnimal::get_type(void) const
{
	return (this->_type);
}
