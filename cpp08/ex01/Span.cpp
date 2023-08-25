
#include "Span.hpp"

//	### Constructor ###

Span::Span(void)
{
	this->_lst.reserve(0);
}

Span::Span(const int n)
{
	this->_lst.reserve(n);
}

Span::Span(Span &t)
{
	std::vector<int>::iterator	start = t._lst.begin();
	std::vector<int>::iterator	end = t._lst.end();

	this->_lst.reserve(t._lst.capacity());
	for(; start != end; start++)
		this->_lst.push_back(*start);
}

//	### Overload Operator ###

Span &Span::operator = (Span &t)
{
	std::vector<int>::iterator	start = t._lst.begin();
	std::vector<int>::iterator	end = t._lst.end();

	this->_lst.clear();
	this->_lst.reserve(t._lst.capacity());
	for(; start != end; start++)
		this->_lst.push_back(*start);
	return (*this);
}

//	### Destructor ###

Span::~Span(void) {}

//	### Member Function ###

void	Span::displayCapacity(void) const
{
	std::cout << "Max capacity of this list : " << this->_lst.capacity() << std::endl;
}

void	Span::displayElements(void)
{
	std::vector<int>::iterator	start = this->_lst.begin();
	std::vector<int>::iterator	end = this->_lst.end();
	
	for (; start != end; start++)
		std::cout << "[" << *start << "]";
	std::cout << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_lst.size() < this->_lst.capacity())
		this->_lst.push_back(n);
	else
		throw (ErrorOverSizeException());
}

int	Span::shortestSpan(void)
{
	std::vector<int>						tmp = this->_lst;

	if (this->_lst.size() < 2)
		throw (ErrorTooFewElementException());

	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator	start = tmp.begin();
	std::vector<int>::iterator	end = tmp.end();

	end--;
	int	min = *(start + 1) - *start;
	for(; start != end; start++)
	{
		if (*(start + 1) - *start < min)
			min = *(start + 1) - *start;
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (this->_lst.size() < 2)
		throw (ErrorTooFewElementException());
	return (*std::max_element(this->_lst.begin(), this->_lst.end()) - 
			*std::min_element(this->_lst.begin(), this->_lst.end()));
}

//	### Exception Function ###

const char	*Span::ErrorOverSizeException::what(void) const throw()
{
	return ("Error : this will go over the maximum size");
}

const char	*Span::ErrorTooFewElementException::what(void) const throw()
{
	return ("Error : List contain not enough elements");
}
