
#include "Dog.hpp"

//	### Constructor ###

Dog::Dog(void) : _brain(new Brain())
{
	AAnimal::_type = "Dog";
	std::cout << "Constructor of a Dog have been called" << std::endl;	
}

Dog::Dog(Dog &t) : _brain(new Brain(*t._brain))
{
	AAnimal::_type = t._type;
	std::cout << "Constructor Copy of a Dog have been called" << std::endl;	
}

//	### Overload Operator ###

Dog &Dog::operator = (const Dog &t)
{
	this->_type = t._type;
	delete (this->_brain);
	this->_brain = new Brain(*t._brain);
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

void	Dog::make_sound(void) const
{
	std::cout << "*Wouf*" << std::endl;
}
