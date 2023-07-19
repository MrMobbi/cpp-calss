
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <ctime>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class Bureaucrat;
class AForm;

class RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &t);
		~RobotomyRequestForm(void);

		void	execute(const Bureaucrat &executor) const;
	private :
		RobotomyRequestForm(void);
		RobotomyRequestForm &operator = (const RobotomyRequestForm &t);
};

#endif
