
#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <exception>
# include <ostream>

class AForm;

class Bureaucrat
{
	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &t);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		gradeUp(void);
		void		gradeDown(void);
		void		reGrade(int new_grade);

		void		signForm(AForm &f) const;
		void		executeForm(const AForm &f) const;

		class	GradeTooHighException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
	private :
		Bureaucrat(void);
		Bureaucrat &operator = (const Bureaucrat &t);

		const std::string	_name;
		int					_grade;
};

std::ostream &operator << (std::ostream &out, const Bureaucrat &t);

#endif
