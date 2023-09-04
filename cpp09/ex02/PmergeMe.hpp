
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include	<deque>
# include <algorithm>
# include <sstream>
# include <string>

class PmergeMe
{
	public :
		PmergeMe(void);
		PmergeMe(char **av);
		PmergeMe(const PmergeMe &t);
		PmergeMe &operator = (const PmergeMe &t);
		~PmergeMe(void);

		bool	isValidInput(std::string str) const;
		void	displayList(void) const;
		void	startSolver(void);

		class ErrorBadInputException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};

		class ErrorDoubleException : public std::exception
		{
			public :
				virtual const char	*what(void) const throw();
		};

		typedef struct s_tab_v {
			std::vector<int>	a;
			std::vector<int>	b;
		}										t_tab_v;

		typedef struct s_tab_d {
			std::deque<int>	a;
			std::deque<int>	b;
		}									t_tab_d;

	private :
		std::vector<int>	_list1;
		std::deque<int>		_list2;
};

#endif
