
#include "ScalarConvert.hpp"

//	### Constructor ###

ScalarConvert::ScalarConvert(void) {}

ScalarConvert::ScalarConvert(const ScalarConvert &t)
{ (void) t; }

//	### Overload Operator ###

ScalarConvert &ScalarConvert::operator = (const ScalarConvert &t)
{
	(void) t;
	std::cout << "Copy assignement operator of ScalarConvert called" << std::endl;
	return (*this);
}

//	### Destructor ###

ScalarConvert::~ScalarConvert(void)
{
	std::cout << "Destructor of ScalarConvert called" << std::endl;
}

//	### Member Function ###

void	nanCase(void)
{ throw(Error::NanCaseException()); }

void	minusInfCase(void)
{ throw(Error::MinusInfCaseException()); }

void	plusInfCase(void)
{ throw(Error::PlusInfCaseException()); }

void	ScalarConvert::pars(const std::string str)
{
	int			sign = 0;
	char		*s = const_cast<char *>(str.c_str());
	std::string	special_case[3] = {"nan", "-inf", "+inf"};
	void		(*fct[3])(void) = {\
				nanCase,\
				minusInfCase,\
				plusInfCase};
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (sign > 0)
				throw(Error::ImpossibleCaseException());
			sign += 1;
		}
		else if (!std::isdigit(s[i]))
			throw(Error::ImpossibleCaseException());
	}
	for (int i = 0; i < 3; i++)
	{
		if (special_case[i] == str)
			(fct[i]());
	}
}

char	ScalarConvert::toChar(const std::string str)
{
	char	*s;
	s = const_cast<char *>(str.c_str());
	if (!isascii(std::atoi(s)))
		throw(Error::ErrorImpossibleException());
	else if (isascii(std::atoi(s)) && !isprint(std::atoi(s)))
		throw(Error::ErrorNonDisplayableException());
	return (std::atoi(s));
}

int	ScalarConvert::toInt(const std::string str)
{
	char	*s = const_cast<char *>(str.c_str());
	char	*s1 = const_cast<char *>(D_MAX_INT);
	if (s[0] == '-')
		s1 = const_cast<char *>(D_MIN_INT);
	if (str.length() > 12)
		throw (Error::ErrorNanException());
	else if (str.length() >= 10)
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] > s1[i])
			throw(Error::ErrorImpossibleException());
	}
	return (std::atoi(str.c_str()));
}

float	ScalarConvert::toFloat(const std::string str)
{
	(void) str;
	return (0);
}

double	ScalarConvert::toDouble(const std::string str)
{
	(void) str;
	return (0);
}

void	ScalarConvert::convert(const std::string str)
{
	try
	{
		ScalarConvert::pars(str);
		std::cout << "str : " << str << std::endl;
		try
		{ std::cout << "char : [" << ScalarConvert::toChar(str) << "]" << std::endl; }
		catch (std::exception &e)
		{ std::cout  << e.what() << "]" << std::endl; }
		try
		{ std::cout << "int : [" << ScalarConvert::toInt(str) << "]" << std::endl; }
		catch (std::exception &e)
		{ std::cout << e.what() << "]" << std::endl; }
		std::cout << "FIN" << std::endl;
	}
	catch (std::exception &e)
	{ std::cout << e.what() << std::endl; }
}
