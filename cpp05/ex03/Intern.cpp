
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

static AForm	*shrubberyCreationFraction(const std::string target)
{ return (new ShrubberyCreationForm(target)); }

static AForm	*robotomyRequestFraction(const std::string target)
{ return (new RobotomyRequestForm(target)); }

static AForm	*presidentialPardonFraction(const std::string target)
{ return (new PresidentialPardonForm(target)); }

AForm	*Intern::makeForm(std::string name, std::string target) const
{
	std::string	name_form[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(*fct[3])(const std::string) = {\
				shrubberyCreationFraction, \
				robotomyRequestFraction, \
				presidentialPardonFraction};
	for (int i = 0; i < 3; i++)
	{
		if (name_form[i] == name)
			return (fct[i](target));
	}
	throw(Intern::NoMatchingFormException());
}

// ### Exception Membre ###

const char *Intern::NoMatchingFormException::what(void) const throw()
{ return ("No Matching Form found."); }
