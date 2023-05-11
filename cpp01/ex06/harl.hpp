
#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class harl
{
	public:
		void	complain(std::string level) const;

		harl(void);
		~harl(void);
	private:
		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;
};

#endif
