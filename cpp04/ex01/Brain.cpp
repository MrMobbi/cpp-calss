
#include "Brain.hpp"

//	### Constructor ###

Brain::Brain(void) : _nb_idea(0)
{
	std::cout << "Constructor of Brain called" << std::endl;
}

Brain::Brain(Brain &t) : _nb_idea(t._nb_idea)
{
	for (int i = 0; i < t._nb_idea; i++)
		this->_idea[i] = t._idea[i];
	std::cout << "Copy constructor of Brain called" << std::endl;
}

//	### Overload Operator ###

Brain &Brain::operator = (const Brain &t)
{
	this->_nb_idea = t._nb_idea;
	for (int i = 0; i < t._nb_idea; i++)
		this->_idea[i] = t._idea[i];
	std::cout << "Copy assignement operator of Brain called" << std::endl;
	return (*this);
}

//	### Destructor ###

Brain::~Brain(void)
{
	std::cout << "Destructor of Brain called" << std::endl;
}

//	### Member Function ###

void	Brain::add_idea(std::string idea)
{
	if (this->_nb_idea == 100)
		std::cout << "My brain is too full, i can't take anymore idea" << std::endl;
	else
		this->_idea[_nb_idea++] = idea;
}

std::string	Brain::get_idea(int nb) const
{
	if (nb >= 1 && nb <= 100)
		return (this->_idea[nb - 1]);
	else
		return (NULL);
}

int	Brain::get_nb_idea(void) const
{
	return (this->_nb_idea);
}
