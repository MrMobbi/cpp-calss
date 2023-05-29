
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap &t);
		FragTrap &operator = (const FragTrap &t);
		~FragTrap(void);

		void	high_five_guys(void);
};

#endif
