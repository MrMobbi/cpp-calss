
#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <exception>
# include <algorithm>

class Span
{
	public :
		Span(const int n);
		Span(Span &t);
		Span &operator = (Span &t);
		~Span(void);

		void	displayCapacity(void) const;
		void	displayElements(void);

		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);

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
