
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class Intern
{
	public :
		Intern(void);
		Intern(const Intern &t);
		Intern &operator = (const Intern &t);
		~Intern(void);
};

#endif