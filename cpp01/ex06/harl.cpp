
#include "harl.hpp"

void	harl::complain(std::string level) const
{
	std::string	str[4] = {"debug", "info", "warning", "error"};	
	void (harl::*tab[4]) (void) const = {&harl::_debug, &harl::_info, &harl::_warning, &harl::_error};
	int			lvl = -1;

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
			lvl = i;
	}

	switch (lvl)
	{
		case 0:
			(this->*tab[0])();
		case 1:
			(this->*tab[1])();
		case 2:
			(this->*tab[2])();
		case 3:
			(this->*tab[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}	
}

harl::harl(void)
{
}

harl::~harl(void)
{
}

void	harl::_debug(void) const
{	
	std::cout << "debug message" << std::endl;
}

void	harl::_info(void) const
{
	std::cout << "info message" << std::endl;
}

void	harl::_warning(void) const
{
	std::cout << "warning message" << std::endl;
}

void	harl::_error(void) const
{
	std::cout << "error message" << std::endl;
}
