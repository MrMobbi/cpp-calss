
#include "Form.hpp"
#include "Bureaucrate.hpp"

//	### Constructor ###

Form::Form(void) : _name("") , _to_sign(0), _to_exec(0), _signed(false) {} 

Form::Form(std::string name, int to_sign, int to_exec) : _name(name), _to_sign(to_sign), _to_exec(to_exec), _signed(false)
{
	if (to_sign <= 0 || to_exec <= 0)
		throw (Form::GradeTooHighException());
	else if (to_sign > 150 || to_exec > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &t) : _name(t._name), _to_sign(t._to_sign), _to_exec(t._to_exec), _signed(t._signed)
{
	if (t._to_sign <= 0 || t._to_exec <= 0)
		throw (Form::GradeTooHighException());
	else if (t._to_sign > 150 || t._to_exec > 150)
		throw (Form::GradeTooLowException());
}

//	### Overload Operator ###

Form &Form::operator = (const Form &t)
{
	(void) t;
	std::cout << "Copy assignement operator of Form called" << std::endl;
	return (*this);
}

//	### Destructor ###

Form::~Form(void)
{
	std::cout << "Destructor of Form called" << std::endl;
}

//	### Member Function ###

const std::string	Form::getName(void) const
{
	return (this->_name);
}

int	Form::getGradeToSign(void) const
{
	return (this->_to_sign);
}

int	Form::getGradeToExec(void) const
{
	return (this->_to_exec);
}

void	Form::beSigned(Bureaucrate *gile)
{
	if (this->_signed == true)
		std::cout << "Form already signed" << std::endl;
	else if (gile->getGrade() > this->_to_sign)
	{
		throw(Form::GradeTooLowException());
		this->_gile = gile;
	}
	else 
	{
		this->_gile = gile;
		this->_signed = true;
		std::cout << "Form succsefully signed" << std::endl;
	}
}

void	Form::signForm(void) const
{
	if (this->_gile != NULL && this->_signed == false)
	{
		std::cout << this->_gile->getName() << " couldn't sign " << Form::getName();
		std::cout << " beacuse grade of the bureaucrate was too low" << std::endl;
	}
	else if (this->_signed == true)
		std::cout << this->_gile->getName() << " signed " << Form::getName() << std::endl;
	else
		std::cout << "Form have not been seen yet" << std::endl;
}

//	### Exception Member ###

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form : Grade too High");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form : Grade too Low");
}

//	### Overloar Operator '<<' ###

std::ostream	&operator << (std::ostream &out, const Form &t)
{
	out << t.getName() << ", Form grade to sign : [" << t.getGradeToSign();
	out << "], grade to execute [" << t.getGradeToExec() << "]" << std::endl;
	return (out);
}
