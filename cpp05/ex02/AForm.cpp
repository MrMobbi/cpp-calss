
#include "AForm.hpp"
#include "Bureaucrat.hpp"

//	### Constructor ###

AForm::AForm(void) : _name("") , _to_sign(0), _to_exec(0), _signed(false) {} 

AForm::AForm(std::string name, int to_sign, int to_exec) : _name(name), _to_sign(to_sign), _to_exec(to_exec), _signed(false)
{
	if (to_sign <= 0 || to_exec <= 0)
		throw (AForm::GradeTooHighException());
	else if (to_sign > 150 || to_exec > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &t) : _name(t._name), _to_sign(t._to_sign), _to_exec(t._to_exec), _signed(t._signed)
{
	if (t._to_sign <= 0 || t._to_exec <= 0)
		throw (AForm::GradeTooHighException());
	else if (t._to_sign > 150 || t._to_exec > 150)
		throw (AForm::GradeTooLowException());
}

//	### Overload Operator ###

AForm &AForm::operator = (const AForm &t)
{
	(void) t;
	std::cout << "Copy assignement operator of AForm called" << std::endl;
	return (*this);
}

//	### Destructor ###

AForm::~AForm(void) 
{ std::cout << "Destructor of AForm called" << std::endl; }

//	### Member Function ###

const std::string	AForm::getName(void) const 
{ return (this->_name); }

int	AForm::getGradeToSign(void) const 
{ return (this->_to_sign); }

int	AForm::getGradeToExec(void) const 
{ return (this->_to_exec); }

bool	AForm::getSigned(void) const 
{ return (this->_signed); }

void	AForm::beSigned(const Bureaucrat &gile)
{
	if (this->_signed == true)
		throw (AForm::FormSignedException());
	else if (gile.getGrade() > this->_to_sign)
		throw (AForm::GradeTooHighException());
	else
	{
		this->_signed = true;
		std::cout << gile.getName() << " signed " << this->_name << std::endl;
	}
}

void	AForm::execute(const Bureaucrat &executor) const
{ (void) executor; }

//	### Exception Member ###

const char	*AForm::GradeTooHighException::what(void) const throw()
{ return ("Form : Grade too High"); }

const char	*AForm::GradeTooLowException::what(void) const throw()
{ return ("Form : Grade too Low"); }

const char	*AForm::FormNotSignedException::what(void) const throw()
{ return ("Form : Is not signed"); }

const char	*AForm::FormSignedException::what(void) const throw()
{ return ("Form : Is already signed"); }

//	### Overloar Operator '<<' ###

std::ostream	&operator << (std::ostream &out, const AForm &t)
{
	out << t.getName() << ", Form grade to sign : [" << t.getGradeToSign();
	out << "], grade to execute [" << t.getGradeToExec() << "]" << std::endl;
	return (out);
}
