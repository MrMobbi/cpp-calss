
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include	<deque>
# include <algorithm>
# include <sstream>
# include <string>
# include <sys/time.h>
# include <iomanip>

template <typename T>
class PmergeMe
{
	public :

//	### Struct Member
		typedef struct s_tab {
			T	a;
			T	b;
		}   t_tab;

//	### Constructor
		PmergeMe(void) {};

		PmergeMe(char **av)
		{
			std::stringstream	ss;
			std::string				word;
			for (int i = 1; av[i] != NULL; i++)
			{
				ss << std::string(av[i]);
				while (ss >> word) 
				{
					isValidInput(word);
					this->_list.push_back(std::atoi(word.c_str()));
				}
				ss.clear();
			}
		};

		PmergeMe(const PmergeMe &t) : _list(t._list) {};

//	### Overload operator'='
		PmergeMe &operator = (const PmergeMe &t)
		{
			this->_list.clear();
			this->_list = t._list;
			return (*this);
		};

//	### Destructor
		~PmergeMe(void) {};

//	### Member Function
		bool	isValidInput(std::string str) const
		{
			std::stringstream	ss(str);
			int			convert;

			ss.clear();
			ss >> convert;
			if (ss.fail() == true)
				throw (ErrorBadInputException());
			else if (str.find_first_not_of("0123456789") != std::string::npos)
				throw (ErrorBadInputException());
			else if (std::find(this->_list.begin(), this->_list.end(), \
						std::atoi(str.c_str())) != this->_list.end())
				throw (ErrorDoubleException());
			return (true);
		};

		void	displayList(std::string	const &str) const
		{
			typename T::const_iterator	itv = this->_list.begin();

			std::cout << str << std::endl;
			for (size_t i = 0;itv != this->_list.end(); itv++)
			{
				if (i > 20)
				{
					std::cout << "[...]";
					break ;
				}
				std::cout << *itv << " ";
				i++;
			}
			std::cout << std::endl;
		};

		void	displayTimeStamp(std::string const &str) const
		{
			std::cout << std::fixed << std::setw(5);
			std::cout << "Time to process range of : " << this->_list.size();
			std::cout << " elements whit std::" << str << " : ";
			std::cout << long((this->_end.tv_sec - this->_start.tv_sec) * 1e6 + \
				(this->_end.tv_usec - this->_start.tv_usec)) << " us" << std::endl;
		};

		void	displayV(T &vec)
		{
			typename T::const_iterator	it = vec.begin();
			for (;it != vec.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		};

		bool	isTopSorted(t_tab &tab)
		{
			for (size_t i = 0; i < tab.a.size() - 1; i++)
			{
				if (tab.a[i] > tab.a[i + 1])
					return (false);
			}
			return (true);
		};

		t_tab	sortTop(t_tab &tab)
		{
			for (size_t i = 0; i < tab.a.size() - 1; i++)
			{
				if (tab.a[i] > tab.a[i + 1])
				{
					std::swap(tab.a[i], tab.a[i + 1]);
					std::swap(tab.b[i], tab.b[i + 1]);
				}
			}
			return (tab);
		};

		t_tab	solveTab(t_tab tab)
		{
			t_tab	lst1;
			t_tab	lst2;
			typename T::iterator	it = tab.a.begin();

			if (tab.a.size() > 2)
			{
				for (size_t i = 0; it != tab.a.end(); it++)
				{
					if (i < tab.a.size() / 2)
					{
						lst1.a.push_back(tab.a[i]);
						lst1.b.push_back(tab.b[i]);
					}
					else
					{
						lst2.a.push_back(tab.a[i]);
						lst2.b.push_back(tab.b[i]);
					}
					i++;
				}
				lst1 = solveTab(lst1);
				lst2 = solveTab(lst2);
			}
			else
			{
				if (tab.a.size() == 2)
				{
					if (tab.a[0] > tab.a[1])
					{
						std::swap(tab.a[0], tab.a[1]);
						std::swap(tab.b[0], tab.b[1]);
					}
				}
				return (tab);
			}

			size_t	j = 0;
			for (size_t i = 0; i < lst1.a.size(); i++)
			{
				tab.a[j] = lst1.a[i];
				tab.b[j] = lst1.b[i];
				j++;
			}
			for (size_t i = 0; i < lst2.a.size(); i++)
			{
				tab.a[j] = lst2.a[i];
				tab.b[j] = lst2.b[i];
				j++;
			}
			while (isTopSorted(tab) == false)
				sortTop(tab);
			return (tab);
		};

		T	solver(T &lst)
		{
			t_tab	tab;
			typename T::iterator	it =	lst.begin();
	
			for (int i = 0; it != lst.end(); it++)
			{
				if (i % 2 == 0)
					tab.a.push_back(*it);
				else
					tab.b.push_back(*it);
				i++;
			}
			if (tab.a.size() != tab.b.size())
				tab.b.push_back(-1);
			int	tmp = 0;
			for (size_t i = 0; i < tab.b.size(); i++)
			{
				if (tab.a[i] < tab.b[i])
				{
					tmp = tab.a[i];
					tab.a[i] = tab.b[i];
					tab.b[i] = tmp;
				}
			}
			tab = solveTab(tab);
			for (size_t i = 0; i < tab.b.size(); i++)
			{
				if (tab.b[i] != -1)
				{
					typename T::iterator	it = std::lower_bound(tab.a.begin(), \
							tab.a.begin() + (2 * i), tab.b[i]);
					tab.a.insert(it, tab.b[i]);
				}
			}
			return (tab.a);
		};

		void	startSolver(void)
		{
			gettimeofday(&this->_start, 0);
			this->_list = solver(this->_list);
			gettimeofday(&this->_end, 0);
		};

//	### Exception Member
		class ErrorBadInputException : public std::exception
		{
			public :
				virtual const char *what(void) const throw()
				{
					return ("Error : Bad Input");
				};
		};

		class ErrorDoubleException : public std::exception
		{
			public :
				virtual const char *what(void) const throw()
				{
					return ("Error : Duplicata found");
				};
		};

	private :
		T	_list;
		struct timeval	_start, _end;
};

#endif
