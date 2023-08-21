
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

const char	*Error::ImpossibleCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [impossible]\ndouble : [impossible]"); }

const char *Error::OutOfRangeException::what(void) const throw()
{ return ("Wrong number value is out of range of the type deteced"); }

const char	*Error::NanCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [nanf]\ndouble : [nan]"); }

const char	*Error::MinusInfCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [-inff]\ndouble : [-inf]"); }

const char	*Error::PlusInfCaseException::what(void) const throw()
{ return ("char : [impossible]\nint : [impossible]\nfloat : [+inff]\ndouble : [+inf]"); }
