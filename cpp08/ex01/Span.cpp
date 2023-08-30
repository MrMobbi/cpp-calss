
#include "Span.hpp"

//	### Constructor ###

Span::Span(void)
{
	this->_lst.reserve(0);
}

Span::Span(unsigned int n)
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

void	Span::displayElements(void) const
{
	std::vector<int>::const_iterator	start = this->_lst.begin();
	std::vector<int>::const_iterator	end = this->_lst.end();
	
	for (; start != end; start++)
		std::cout << "[" << *start << "]";
	std::cout << std::endl;
}

void	Span::insertNumber(std::vector<int>::iterator begin,
		std::vector<int>::iterator end)
{
	if (this->_lst.size() + (end - begin) < this->_lst.capacity())
		this->_lst.insert(_lst.end(), begin, end);
	else
		throw (ErrorOverSizeException());
	std::cout << this->_lst.size() + (end - begin) << std::endl;
}

void	Span::addNumber(int n)
{
	if (this->_lst.size() < this->_lst.capacity())
		this->_lst.push_back(n);
	else
		throw (ErrorOverSizeException());
}

int	Span::shortestSpan(void) const
{
	std::vector<int>	tmp = this->_lst;
	std::vector<int>	sorted;

	if (this->_lst.size() < 2)
		throw (ErrorTooFewElementException());
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(sorted));
	return (*min_element(sorted.begin() + 1, sorted.end())); 
}

int	Span::longestSpan(void) const
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
