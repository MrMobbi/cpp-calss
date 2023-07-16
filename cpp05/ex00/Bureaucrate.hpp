
#ifndef BUREAUCRATE_HPP
# define BUREAUCRATE_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <exception>
# include <ostream>

class Bureaucrate
{
	public :
		Bureaucrate(std::string name, int grade);
		Bureaucrate(const Bureaucrate &t);
		~Bureaucrate(void);

		std::string	getName(void) const;
		int			getGrade(void) const;
		void		gradeUp(void);
		void		gradeDown(void);

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
		Bureaucrate(void);
		Bureaucrate &operator = (const Bureaucrate &t);

		std::string	_name;
		int			_grade;
};

#endif
