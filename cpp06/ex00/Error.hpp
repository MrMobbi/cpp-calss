
#ifndef ERROR_HPP
# define ERROR_HPP

# include <iostream>
# include <string>
# include <exception>

class Error
{
	public :
		~Error(void);

		class ErrorImpossibleException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class ErrorNonDisplayableException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class ErrorNanException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class ImpossibleCaseException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class NanCaseException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class MinusInfCaseException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class PlusInfCaseException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

	private :
		Error(void);
		Error(const Error &t);
		Error &operator = (const Error &t);
};

#endif
