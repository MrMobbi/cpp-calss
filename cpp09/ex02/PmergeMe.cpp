
#include "PmergeMe.hpp"

//	### Constructor ###

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **av)
{
	std::stringstream	ss;
	std::string				word;
	for (int i = 1; av[i] != NULL; i++)
	{
		ss << std::string(av[i]);
		while (ss >> word) 
		{
			isValidInput(word);
			this->_list1.push_back(std::atoi(word.c_str()));
			this->_list2.push_back(std::atoi(word.c_str()));
		}
		ss.clear();
	}
}

PmergeMe::PmergeMe(const PmergeMe &t) : _list1(t._list1), _list2(t._list2) {}

//	### Overload Operator ###

PmergeMe &PmergeMe::operator = (const PmergeMe &t)
{
	this->_list1.clear();
	this->_list2.clear();
	this->_list1 = t._list1;
	this->_list2 = t._list2;
	return (*this);
}

//	### Destructor ###

PmergeMe::~PmergeMe(void) {}

//	### Member Function ###

bool	PmergeMe::isValidInput(std::string str) const
{
	std::stringstream	ss(str);
	int			convert;

	ss.clear();
	ss >> convert;
	if (ss.fail() == true)
		throw (ErrorBadInputException());
	else if (str.find_first_not_of("0123456789") != std::string::npos)
		throw (ErrorBadInputException());
	else if (std::find(this->_list1.begin(), this->_list1.end(), \
				std::atoi(str.c_str())) != this->_list1.end())
		throw (ErrorDoubleException());
	return (true);
}

void	PmergeMe::displayList(void) const
{
	std::vector<int>::const_iterator	itv = this->_list1.begin();

	std::cout << "vector : " << std::endl;
	for (;itv != this->_list1.end(); itv++)
		std::cout << *itv << " ";
	std::cout << std::endl;

	std::deque<int>::const_iterator	itd = this->_list2.begin();

	std::cout << "deque : " << std::endl;
	for (;itd != this->_list2.end(); itd++)
		std::cout << *itd << " ";
	std::cout << std::endl;
}

void	displayV(std::vector<int> &vec)
{
	std::vector<int>::const_iterator	it = vec.begin();
	for (;it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

PmergeMe::t_tab_v	solveTab(PmergeMe::t_tab_v tab)
{
	PmergeMe::t_tab_v	lst1;
	PmergeMe::t_tab_v	lst2;
	std::vector<int>::iterator	it = tab.a.begin();

	if (tab.a.size() > 2)
	{
		for (int i = 0; it != tab.a.end(); it++)
		{
			if (i % 2 == 0)
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
		if (tab.a.size() != 2)
		{
			if (tab.a[0] > tab.a[1])
			{
				std::swap(tab.a[0], tab.a[1]);
				std::swap(tab.b[0], tab.b[1]);
			}
		}
		std::cout << "tab.a.size() <= 2 :" << std::endl;
		displayV(tab.a);
		displayV(tab.b);
	}
	return (tab);
}

std::vector<int>	solverV(std::vector<int> &lst)
{
	PmergeMe::t_tab_v						tab;
	std::vector<int>	solved;
	std::vector<int>::iterator it = lst.begin();
	
	std::cout << std::endl;
	std::cout << "IN THE SOLVER" << std::endl;
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
	displayV(tab.a);
	displayV(tab.b);
	std::cout << "sorting the thirst one:" << std::endl;
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
	displayV(tab.a);
	displayV(tab.b);
	tab = solveTab(tab);
	return (solved);
}

void	PmergeMe::startSolver(void)
{
	this->_list1 = solverV(this->_list1);
}

//	### Exception Member ###

const char	*PmergeMe::ErrorBadInputException::what(void) const throw()
{
	return ("Error : Bad input");
}

const char	*PmergeMe::ErrorDoubleException::what(void) const throw()
{
	return ("Error : Double in list");
}
