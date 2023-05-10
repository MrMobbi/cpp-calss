
#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
	public:
		void	attack(void) const;
		void	set_weapon(Weapon &weapon);
		HumanB(void);
		HumanB(std::string name);
		~HumanB(void);
	private:
		Weapon		*_weapon;
		std::string	_name;
};

#endif
