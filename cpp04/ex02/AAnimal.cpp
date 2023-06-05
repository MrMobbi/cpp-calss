
#include "AAnimal.hpp"

//	### Constructor ###

AAnimal::AAnimal(void) : _type("None")
{
	std::cout << "Constructor of an AAnimal have been called" << std::endl;	
}

AAnimal::AAnimal(AAnimal &t) : _type(t._type)
{
	std::cout << "Constructor Copy of an AAnimal have been called" << std::endl;	
}

//	### Overload Operator ###

AAnimal &AAnimal::operator = (const AAnimal &t)
{
	this->_type = t._type;
	return (*this);
	std::cout << "Copy Assigment of an AAnimal have been called" << std::endl;	
}

//	### Destructor ###

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor of a Anmial have been called" << std::endl;
}

//	### Member Function ###

void	AAnimal::make_sound(void) const
{
	if (this->_type == "None")
		std::cout << "*Inaudible sound*" << std::endl;
	else if (this->_type == "Cat")
		std::cout << "*Meow*" << std::endl;
	else if (this->_type == "Dog")
		std::cout << "*Wouf*" << std::endl;
}

std::string	AAnimal::get_type(void) const
{
	return (this->_type);
}
