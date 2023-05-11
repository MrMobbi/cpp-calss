
#include "harl.hpp"

void	harl::complain(std::string level) const
{
	std::string	str[4] = {"debug", "info", "warning", "error"};	
	void (harl::*tab[4]) (void) const = {&harl::_debug, &harl::_info, &harl::_warning, &harl::_error};

	for (int i = 0; i < 4; i++)
	{
		if (level == str[i])
			(this->*tab[i])();
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
