
#include "PresidentialPardonForm.hpp"

//	### Constructor ###

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("President Pardon", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{	std::cout << "Presidential Pardon created" << std::endl; }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &t) : AForm(t) {}

//	### Overload Operator ###

PresidentialPardonForm &PresidentialPardonForm::operator = (const PresidentialPardonForm &t)
{
	(void) t;
	std::cout << "Copy assignement operator of PresidentialPardonForm called" << std::endl;
	return (*this);
}

//	### Destructor ###

PresidentialPardonForm::~PresidentialPardonForm(void)
{ std::cout << "Destructor of PresidentialPardonForm called" << std::endl; }

//	### Member Function ###

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooHighException());
	else
		std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
