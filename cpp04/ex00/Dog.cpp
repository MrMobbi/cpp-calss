
#include "Dog.hpp"

//	### Constructor ###

Dog::Dog(void)
{
	Animal::_type = "Dog";
	std::cout << "Constructor of a Dog have been called" << std::endl;	
}

Dog::Dog(Dog &t)
{
	Animal::_type = t._type;
	std::cout << "Constructor Copy of a Dog have been called" << std::endl;	
}

//	### Overload Operator ###

Dog &Dog::operator = (const Dog &t)
{
	this->_type = t._type;
	return (*this);
	std::cout << "Copy Assigment of a Dog have been called" << std::endl;	
}

//	### Destructor ###

Dog::~Dog(void)
{
	std::cout << "Destructor of a Dog have been called" << std::endl;
}

void	Dog::make_sound(void) const
{
	std::cout << "*Wouaf*" << std::endl;
}
