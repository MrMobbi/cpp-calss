
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

		typedef typename std::stack<t_type>::container_type ::iterator								iterator;
		typedef typename std::stack<t_type>::container_type ::const_iterator					const_iterator;
		typedef typename std::stack<t_type>::container_type ::reverse_iterator				reverse_iterator;
		typedef typename std::stack<t_type>::container_type ::const_reverse_iterator	const_reverse_iterator;
		
		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}
		
		const_iterator	begin(void) const
		{
			return (this->c.begin());
		}

		const_iterator	end(void) const
		{
			return (this->c.end());
		}

		reverse_iterator	rbegin(void)
		{
			return (this->c.rbegin());
		}

		reverse_iterator	rend(void)
		{
			return (this->c.rend());
		}

		const_reverse_iterator	rbegin(void) const
		{
			return (this->c.rbegin());
		}

		const_reverse_iterator	rend(void) const
		{
			return (this->c.rend());
		}
};

#endif
