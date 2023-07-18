
#include "Bureaucrat.hpp"

//	### Constructor ###

Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade <= 0)
	{
		this->_grade = 150;
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (grade > 150)
	{
		this->_grade = 150;
		throw (Bureaucrat::GradeTooLowException());
	}
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &t) : _name(t._name)
{
	if (t._grade <= 0)
	{
		this->_grade = 150;
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (t._grade > 150)
	{
		this->_grade = 150;
		throw (Bureaucrat::GradeTooLowException());
	}
	else
		this->_grade = t._grade;
}

//	### Overload Operator ###

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &t)
{
	(void) t;
	return (*this);
}

//	### Destructor ###

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor of Bureaucrat called" << std::endl;
}

//	### Member Function ###

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::gradeUp(void)
{
	if (this->_grade - 1 <= 0)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::gradeDown(void)
{
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade it too high, cannot go over 1!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{

	return ("Grade it too low, cannot go under 150!");
}

//	### Overload operator '<<' ###

std::ostream	&operator << (std::ostream &out, const Bureaucrat &t)
{
	out << t.getName() << ", bureaucrate grade : [" << t.getGrade() << "]";
	return (out);
}
