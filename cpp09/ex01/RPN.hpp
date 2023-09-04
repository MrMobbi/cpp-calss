
#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <list>
# include <algorithm>
# include <sstream>
# include <fstream>
# include <cctype>
# include <string>

class RPN
{
	public :
		RPN(void);
		RPN(char **av);
		RPN(const RPN &t);
		RPN &operator = (const RPN &t);
		~RPN(void);

		void	displayPrompt(void) const;
		void	displayNumber() const;
		bool	isValidInput(std::string str) const;
		void	isPromptValid(void) const;
		void	solve(void);

		class ErrorInputException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};

	private :
		std::list<std::string>	_prompt;
		std::list<int>					_number;
};

#endif
