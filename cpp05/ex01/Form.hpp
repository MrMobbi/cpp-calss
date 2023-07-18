 
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <exception>
# include <ostream>

class Bureaucrate;

class Form
{
	public :
		Form(std::string name, int to_sign, int to_exec);
		Form(const Form &t);
		~Form(void);

		const std::string	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;

		void				beSigned(Bureaucrate *gile);
		void				signForm(void) const;

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
		Form(void);
		Form &operator = (const Form &t);

		const std::string	_name;
		const int			_to_sign;
		const int			_to_exec;
		bool				_signed;
		Bureaucrate			*_gile;

};

std::ostream &operator << (std::ostream &out, const Form &t);

#endif
