 
#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <exception>
# include <ostream>

class Bureaucrat;

class AForm
{
	public :
		AForm(std::string name, int to_sign, int to_exec);
		AForm(const AForm &t);
		~AForm(void);

		const std::string	getName(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		bool				getSigned(void) const;

		void				beSigned(const Bureaucrat &gile);
		virtual void		execute(const Bureaucrat &executor) const;
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
		class	FormNotSignedException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
		class	FormSignedException : public std::exception
		{
			public :
				virtual const char *what(void) const throw();
		};
	private :
		AForm(void);
		AForm &operator = (const AForm &t);

		const std::string	_name;
		const int			_to_sign;
		const int			_to_exec;
		bool				_signed;
};

std::ostream &operator << (std::ostream &out, const AForm &t);

#endif
