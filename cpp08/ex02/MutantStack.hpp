
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>

template<typename t_type>
class	MutantStack : public std::stack<t_type>
{
	public :
		MutantStack(void) {};
		MutantStack(MutantStack &t) {
			*this = t;
		}
		MutantStack &operator = (MutantStack &t) {
			std::stack<t_type>::operator=(t);
			return (*this);
		}
		~MutantStack(void) {};
};

#endif
