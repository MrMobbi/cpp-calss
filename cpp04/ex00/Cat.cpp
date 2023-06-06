
#include "Cat.hpp"

//	### Constructor ###

Cat::Cat(void)
{
	Animal::_type = "Cat";
	std::cout << "Constructor of a Cat have been called" << std::endl;	
}

Cat::Cat(Cat &t)
{
	Animal::_type = t._type;
	std::cout << "Constructor Copy of a Cat have been called" << std::endl;	
}

//	### Overload Operator ###

Cat &Cat::operator = (const Cat &t)
{
	this->_type = t._type;
	return (*this);
	std::cout << "Copy Assigment of a Cat have been called" << std::endl;	
}

//	### Destructor ###

Cat::~Cat(void)
{
	std::cout << "Destructor of a Cat have been called" << std::endl;
}

void	Cat::make_sound(void) const
{
	std::cout << "*miaou*" << std::endl;
}
