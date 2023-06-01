
#include "Dog.hpp"

//	### Constructor ###

Dog::Dog(void) : _brain(new Brain())
{
	Animal::_type = "Dog";
	std::cout << "Constructor of a Dog have been called" << std::endl;	
}

Dog::Dog(Dog &t) : _brain(t._brain)
{
	Animal::_type = t._type;
	std::cout << "Constructor Copy of a Dog have been called" << std::endl;	
}

//	### Overload Operator ###

Dog &Dog::operator = (const Dog &t)
{
	this->_type = t._type;
	this->_brain = t._brain;
	return (*this);
	std::cout << "Copy Assigment of a Dog have been called" << std::endl;	
}

//	### Destructor ###

Dog::~Dog(void)
{
	delete(_brain);
	std::cout << "Destructor of a Dog have been called" << std::endl;
}

//	### Member Function ###

void	Dog::new_idea(std::string idea) const
{
	this->_brain->add_idea(idea);
}

void	Dog::print_idea(int nb) const
{
	if (nb > this->_brain->get_nb_idea())
		std::cout << "Number is non valid! Enter a Number between 1 and 100" << std::endl;
	else
		std::cout << this->_brain->get_idea(nb) << std::endl;
}
