
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &t);
		~ShrubberyCreationForm(void);

		std::string	nameFile(void) const;
		void		execute(const Bureaucrat &executor) const;
	private :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &t);
};

#endif
