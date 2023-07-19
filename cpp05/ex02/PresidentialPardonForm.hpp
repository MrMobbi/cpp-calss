
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &t);
		~PresidentialPardonForm(void);

		void	execute(const Bureaucrat &executor) const;
	private :
		PresidentialPardonForm(void);
		PresidentialPardonForm &operator = (const PresidentialPardonForm &t);
};

#endif
