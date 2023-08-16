
#include "Error.hpp"

//	### Constructor ###

Error::Error(void) {}

Error::Error(const Error &t)
{ (void) t; }

//	### Overload Operator ###

Error &Error::operator = (const Error &t)
{
	(void) t;
	return (*this);
}

//	### Destructor ###

Error::~Error(void) {}

//	### Exception Member Function ###

const char	*Error::ErrorImpossibleException::what(void) const throw()
{ return ("impossible"); }

const char	*Error::ErrorNonDisplayableException::what(void) const throw()
{ return ("Non displayable"); }

const char	*Error::ErrorNanException::what(void) const throw()
{ return ("nan"); }

const char	*Error::ImpossibleCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [impossible]\ndouble : [impossible]"); }

const char	*Error::NanCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [nanf]\ndouble : [nan]"); }

const char	*Error::MinusInfCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [-inff]\ndouble : [-inf]"); }

const char	*Error::PlusInfCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [+inff]\ndouble : [+inf]"); }
