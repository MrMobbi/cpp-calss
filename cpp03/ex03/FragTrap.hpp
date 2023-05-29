
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : virtual public ClapTrap
{
	public :
		FragTrap(void);
		FragTrap(int _hp, int _ep, int _ad, std::string name); 
		FragTrap(std::string name);
		FragTrap(FragTrap &t);
		FragTrap &operator = (const FragTrap &t);
		~FragTrap(void);

		void		high_five_guys(void);
	protected :
		int _default_hp;;
		int	_default_ep;
		int	_default_ad;
};

#endif
