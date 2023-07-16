
#include "Bureaucrate.hpp"

//	### Constructor ###

Bureaucrate::Bureaucrate(void) {}

Bureaucrate::Bureaucrate(std::string name, int grade) : _name(name)
{
	try
	{
		if (grade <= 0)
			throw (Bureaucrate::GradeTooHighException());
		else if (grade > 150)
			throw (Bureaucrate::GradeTooLowException());
		else
			this->_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

Bureaucrate::Bureaucrate(const Bureaucrate &t) : _name(t._name)
{
	try
	{
		if (t._grade <= 0)
			throw (Bureaucrate::GradeTooHighException());
		else if (t._grade > 150)
			throw (Bureaucrate::GradeTooLowException());
		else
			this->_grade = t._grade;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

//	### Overload Operator ###

Bureaucrate &Bureaucrate::operator = (const Bureaucrate &t)
{
	(void) t;
	return (*this);
}

//	### Destructor ###

Bureaucrate::~Bureaucrate(void)
{
	std::cout << "Destructor of Bureaucrate called" << std::endl;
}

//	### Member Function ###

std::string	Bureaucrate::getName(void) const
{
	return (this->_name);
}

int	Bureaucrate::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrate::gradeUp(void)
{
	try
	{
		if (this->_grade - 1 <= 0)
			throw (Bureaucrate::GradeTooHighException());
		else
			this->_grade--;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Bureaucrate::gradeDown(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw (Bureaucrate::GradeTooLowException());
		else
			this->_grade++;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char	*Bureaucrate::GradeTooHighException::what(void) const throw()
{
	return ("Grade it too high, cannot go over 1!");
}

const char	*Bureaucrate::GradeTooLowException::what(void) const throw()
{

	return ("Grade it too low, cannot go under 150!");
}
