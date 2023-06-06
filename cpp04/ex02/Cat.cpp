
#include "Cat.hpp"

//	### Constructor ###

Cat::Cat(void) : _brain(new Brain())
{
	AAnimal::_type = "Cat";
	std::cout << "Constructor of a Cat have been called" << std::endl;	
}

Cat::Cat(Cat &t) : _brain(new Brain(*t._brain))
{
	AAnimal::_type = t._type;
	std::cout << "Constructor Copy of a Cat have been called" << std::endl;	
}

//	### Overload Operator ###

Cat &Cat::operator = (const Cat &t)
{
	this->_type = t._type;
	delete (this->_brain);
	this->_brain = new Brain(*t._brain);
	return (*this);
	std::cout << "Copy Assigment of a Cat have been called" << std::endl;	
}

//	### Destructor ###

Cat::~Cat(void)
{
	delete(_brain);
	std::cout << "Destructor of a Cat have been called" << std::endl;
}

//	### Member Function ###

void	Cat::new_idea(std::string idea) const
{
	this->_brain->add_idea(idea);
}

void	Cat::print_idea(int nb) const
{
	if (nb > this->_brain->get_nb_idea())
		std::cout << "Number is non valid! Enter a Number between 1 and 100" << std::endl;
	else
		std::cout << this->_brain->get_idea(nb) << std::endl;
}

void	Cat::make_sound(void) const
{
	std::cout << "*Meow*" << std::endl;
}
