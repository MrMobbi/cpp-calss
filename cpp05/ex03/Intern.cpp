
#include "Intern.hpp"

//	### Constructor ###

Intern::Intern(void) {}

Intern::Intern(const Intern &t) { (void) t; }

//	### Overload Operator ###

Intern &Intern::operator = (const Intern &t)
{
	(void) t;
	return (*this);
}

//	### Destructor ###

Intern::~Intern(void)
{
	std::cout << "Destructor of Intern called" << std::endl;
}

//	### Member Function ###

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	AForm	*form = NULL;

	if (name == "shrubbery creation")
		form = new ShrubberyCreationForm(target);
	else if (name == "robotomy request")
		form = new RobotomyRequestForm(target);
	else if (name == "presidential pardon")
		form = new PresidentialPardonForm(target);
	else
	{
		std::cout << "Intern canot create this Form" << std::endl;
		return (NULL);
	}
	std::cout << "Intern creates " << name << std::endl;
	return (form);
}
