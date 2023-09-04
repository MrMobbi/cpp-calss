
#include "RPN.hpp"

//	### Constructor ###

RPN::RPN(void) {}

RPN::RPN(char **av) 
{
	std::stringstream	ss;
	std::string				word;
	for (int i = 1; av[i] != NULL; i++)
	{
		ss << std::string(av[i]);
		while (ss >> word) 
		{
			isValidInput(word);
			this->_prompt.push_back(word);
		}
		ss.clear();
	}
	isPromptValid();
}

RPN::RPN(const RPN &t) : _prompt(t._prompt), _number(t._number) {}

//	### Overload Operator ###

RPN &RPN::operator = (const RPN &t)
{
	this->_prompt.clear();
	this->_number.clear();
	this->_prompt = t._prompt;
	this->_number = t._number;
	return (*this);
}

//	### Destructor ###

RPN::~RPN(void) {}

//	### Member Function ###

void	RPN::displayPrompt(void) const
{
	std::list<std::string>::const_iterator	it = this->_prompt.begin();

	while (it != this->_prompt.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
}

void	RPN::displayNumber() const
{
	std::list<int>::const_iterator	it = this->_number.begin();

	while (it != this->_number.end())
	{
		std::cout << *it  << " ";
		it++;
	}
}

bool	RPN::isValidInput(std::string str) const
{
	if (str.size() != 1)
		throw (ErrorInputException());
	if (str == "+" || str == "-" || str == "/" || str == "*")
		return (true);
	else if (str.find_first_not_of("0123456789") != std::string::npos)
		throw (ErrorInputException());
	return (true);
}

void	RPN::isPromptValid(void) const
{
	int	valid = 0;	
	std::list<std::string>::const_iterator	it = this->_prompt.begin();

	if (this->_prompt.size() == 1)
		throw (ErrorInputException());
	while (it != this->_prompt.end())
	{
		if (it->find_first_not_of("0123456789") != std::string::npos)
		{
			valid--;
			if (valid < 1)
				throw (ErrorInputException());
		}
		else
			valid++;
		it++;
	}
}

void	RPN::solve(void)
{
	std::list<std::string>::iterator	it = this->_prompt.begin();
	int	tmp = 0;

	while (it != this->_prompt.end())
	{
		if (it->find_first_not_of("0123456789") == std::string::npos)
		{
			this->_number.push_back(std::atoi(it->c_str()));
			this->displayNumber();
			std::cout << std::endl;
		}
		else
		{
			tmp = this->_number.back();
			this->_number.pop_back();
			if (*it == "+")
				tmp = this->_number.back() + tmp;
			else if (*it == "-")
				tmp = this->_number.back() - tmp;
			else if (*it == "*")
				tmp = this->_number.back() * tmp;
			else if (*it == "/")
				tmp = this->_number.back() / tmp;
			this->_number.pop_back();
			this->_number.push_back(tmp);
			this->displayNumber();
			std::cout << *it << std::endl;
		}
		it++;
	}
	std::cout << "Result :\n";
	this->displayNumber();
	std::cout << std::endl;
}

//	###	Exception Member ###

const char	*RPN::ErrorInputException::what(void) const throw()
{
	return ("Error : Bad input.");
}
