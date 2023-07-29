
#include "RobotomyRequestForm.hpp"

//	### Constructor ###

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &t) : AForm(t) {}

//	### Overload Operator ###

RobotomyRequestForm &RobotomyRequestForm::operator = (const RobotomyRequestForm &t)
{
	(void) t;
	std::cout << "Copy assignement operator of RobotomyRequestForm called" << std::endl;
	return (*this);
}

//	### Destructor ###

RobotomyRequestForm::~RobotomyRequestForm(void)
{ std::cout << "Destructor of RobotomyRequestForm called" << std::endl; }

//	### Member Function ###

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());
	else if (executor.getGrade() > this->getGradeToExec())
		throw (AForm::GradeTooHighException());
	else
	{
		std::time_t result = std::time(NULL);
		std::cout << "pew, pew, zzzzzzttti, Brum-rum-rum-rum, click!" <<std::endl;
		if (result % 2 == 0)
			std::cout << this->getName() << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy failed!" << std::endl;
	}
}
