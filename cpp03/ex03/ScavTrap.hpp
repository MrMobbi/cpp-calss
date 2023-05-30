
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(int _hp, int _ep, int _ad, std::string name);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &t);
		ScavTrap &operator = (const ScavTrap &t);
		~ScavTrap(void);

		void		attack(const std::string target);
		void		guard_gate(void);
	protected :
		bool	_guard_mode;
		int	_default_hp;;
		int	_default_ep;
		int	_default_ad;
};

#endif
