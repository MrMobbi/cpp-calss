
#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public :
		Intern(void);
		Intern(const Intern &t);
		Intern &operator = (const Intern &t);
		~Intern(void);

		AForm	*makeForm(std::string name, std::string target) const;

		class	NoMatchingFormException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
};

#endif
