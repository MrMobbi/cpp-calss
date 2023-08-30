
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iterator>
# include <vector>
# include <exception>
# include <algorithm>
# include <numeric>

class Span
{
	public :
		Span(unsigned int n);
		Span(Span &t);
		Span &operator = (Span &t);
		~Span(void);

		void	displayCapacity(void) const;
		void	displayElements(void) const;

		void	insertNumber(std::vector<int>::iterator begin, 
				std::vector<int>::iterator end);
		void	addNumber(int n);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		class ErrorOverSizeException : public std::exception
		{
			virtual const char *what(void) const throw();
		};

		class ErrorTooFewElementException : public std::exception
		{
			virtual const char *what(void) const throw();
		};

	private :
		Span(void);
		std::vector<int>	_lst;
};

#endif
