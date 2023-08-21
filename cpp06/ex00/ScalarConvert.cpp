
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

int	getPrecision(std::string str)
{
	char	*s = const_cast<char *>(str.c_str());
	int		count = 0;
	
	while (*s != '\0')
	{
		if (*s == '.' && s[1] != '\0')
		{
			for (int i = 0; s[i] != '\0'; i++)
				count++;
			return (count - 1);
		}
		s++;
	}
	return (1);
}

bool	pars(const std::string str)
{
	int			sign = 0;
	int			comma = 0;
	int			is_float = 0;
	char		*s = const_cast<char *>(str.c_str());
	std::string	special_case[3] = {"nan", "-inf", "+inf"};
	void		(*fct[3])(void) = {\
				nanCase,\
				minusInfCase,\
				plusInfCase};
	if (str.length() <= 0)
		return (false);
	if (str.length() == 1)
		return (true);
	for (int i = 0; i < 3; i++)
	{
		if (special_case[i] == str)
			(fct[i]());
	}
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			if (sign > 0)
			return (false);
			sign += 1;
		}
		else if (s[i] == '.')
		{
			if (comma > 0)
			return (false);
			comma += 1;
		}
		else if (s[i] == 'f')
		{
			if (is_float > 0)
			return (false);
			is_float += 1;
		}
		else if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool	isValidChar (int c)
{
	if (!isascii(c))
	{
		std::cout << "char : [impossible]" << std::endl;
		return (false);
	}
	else if (isascii(c) && !std::isprint(c))
	{
		std::cout << "char : [non printable]" << std::endl;
		return (false);
	}
	return (true);
}

void	showValue(int c, int i, float f, double d, int precision)
{
	if (isValidChar(c) == true)
		std::cout << "char : [" << static_cast<char>(c) << "]" << std::endl;
	std::cout << "int : [" << i << "]" << std::endl;
	std::cout << "float : [" << std::fixed << std::setprecision(precision) << f << "f]" << std::endl;
	std::cout << "double : [" << std::fixed << std::setprecision(precision) << d << "]" << std::endl;
}

void	showValueOutOfRange(float f, double d, int precision)
{
	std::cout << "char : [impossible]" << std::endl;
	std::cout << "int : [impossible]" << std::endl;
	std::cout << "float : [" << std::fixed << std::setprecision(precision) << f << "f]" << std::endl;
	std::cout << "double : [" << std::fixed << std::setprecision(precision) << d << "]" << std::endl;
}

void	toChar(const std::string str)
{
	std::stringstream	ss(str);
	char				value;

	ss.clear();
	ss >> value;
	showValue(value, static_cast<int>(value), static_cast<float>(value), static_cast<double>(value), getPrecision(str));
}

void	toInt(const std::string str)
{
	std::stringstream	ss(str);
	int					value;

	ss.clear();
	ss >> value;
	if (ss.fail() == true)
		throw(Error::OutOfRangeException());
	showValue(static_cast<int>(value), value, static_cast<float>(value), static_cast<double>(value), getPrecision(str));
}

void	toFloat(std::string str)
{
	str.pop_back();
	std::stringstream	ss(str);
	std::stringstream	ss1(str);
	float				value;
	int					test;

	ss.clear();
	ss >> value;
	if (ss.fail() == true)
		throw(Error::OutOfRangeException());
	ss1.clear();
	ss1 >> test;
	if (ss1.fail() == true)
		showValueOutOfRange(value, static_cast<double>(value), getPrecision(str));
	else
		showValue(static_cast<int>(value), static_cast<int>(value), value, static_cast<double>(value), getPrecision(str));
}

void	toDouble(const std::string str)
{
	std::stringstream	ss(str);
	std::stringstream	ss1(str);
	double				value;
	int					test;

	ss.clear();
	ss >> value;
	if (ss.fail() == true)
		throw(Error::OutOfRangeException());
	ss1.clear();
	ss1 >> test;
	if (ss1.fail() == true)
		showValueOutOfRange(static_cast<float>(value), value, getPrecision(str));
	else
		showValue(static_cast<int>(value), static_cast<int>(value), static_cast<float>(value), value, getPrecision(str));
}

void	ScalarConvert::convert(const std::string str)
{
	if (pars(str) == false)
		throw(Error::ImpossibleCaseException());
	if (str.length() == 1)
		toChar(str);
	else if (str.back() == 'f')
		toFloat(str);
	else if (str.find('.') != std::string::npos)
		toDouble(str);
	else
		toInt(str);
}
