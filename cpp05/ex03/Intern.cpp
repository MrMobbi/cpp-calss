
#include "Intern.hpp"

//	### Constructor ###

Intern::Intern(void)
{
	std::cout << "Constructor of Intern called" << std::endl;
}

Intern::Intern(const Intern &t)
{
	(void) t;
	std::cout << "Copy constructor of Intern called" << std::endl;
}

//	### Overload Operator ###

Intern &Intern::operator = (const Intern &t)
{
	(void) t;
	std::cout << "Copy assignement operator of Intern called" << std::endl;
	return (*this);
}

//	### Destructor ###

Intern::~Intern(void)
{
	std::cout << "Destructor of Intern called" << std::endl;
}

//	### Member Function ###

