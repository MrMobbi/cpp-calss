
#include "Animal.hpp"

//	### Constructor ###

Animal::Animal(void) : _type("None")
{
	std::cout << "Constructor of an Animal have been called" << std::endl;	
}

Animal::Animal(Animal &t) : _type(t._type)
{
	std::cout << "Constructor Copy of an Animal have been called" << std::endl;	
}

//	### Overload Operator ###

Animal &Animal::operator = (const Animal &t)
{
	this->_type = t._type;
	return (*this);
	std::cout << "Copy Assigment of an Animal have been called" << std::endl;	
}

//	### Destructor ###

Animal::~Animal(void)
{
	std::cout << "Destructor of a Anmial have been called" << std::endl;
}

//	### Member Function ###

void	Animal::make_sound(void) const
{
	if (this->_type == "None")
		std::cout << "*Inaudible sound*" << std::endl;
	else if (this->_type == "Cat")
		std::cout << "*Meow*" << std::endl;
	else if (this->_type == "Dog")
		std::cout << "*Wouf*" << std::endl;
}

std::string	Animal::get_type(void) const
{
	return (this->_type);
}
