
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <list>
# include <vector>
# include <algorithm>

class ErrorNotFoundException : public std::exception
{
	public :
		virtual const	char *what(void) const throw()
		{
			return ("Value not found");
		}
};

template<typename t_type>
typename t_type::iterator easyfind(t_type &lst, int n)
{
	typename t_type::iterator is_find = std::find(lst.begin(), lst.end(), n);
	if (is_find == lst.end())
		throw(ErrorNotFoundException());
	return (is_find);
}

#endif
