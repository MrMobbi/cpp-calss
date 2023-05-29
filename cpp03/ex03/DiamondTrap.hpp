
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap &t);
		DiamondTrap &operator = (const DiamondTrap &t);
		~DiamondTrap(void);
	
		void	who_am_i(void) const;
	private :
		std::string	_name;
};

#endif
