
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap &t);
		ScavTrap &operator = (const ScavTrap &t);
		~ScavTrap(void);

		void	attack(const std::string target);
		void	guard_gate(void);
		void	show_stat(void) const;
	protected :
		bool	_guard_mode;
};

#endif
