
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <algorithm>

template<typename t_type>
class	MutantStack : public std::stack<t_type>
{
	public :
		MutantStack(void) {};
		MutantStack(MutantStack &t) : std::stack<t_type>(t)
		{
			*this = t;
		}
		MutantStack &operator = (MutantStack &t) 
		{
			std::stack<t_type>::operator=(t);
			return (*this);
		}
		~MutantStack(void) {};

		typedef typename std::stack<t_type>::container_type ::iterator	iterator;
		typedef typename std::stack<t_type>::container_type ::const_iterator	const_iterator;
		
		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}
};

#endif
