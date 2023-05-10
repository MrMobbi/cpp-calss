
#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanA
{
	public:
		void	attack(void) const;
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
	private:
		Weapon		&_weapon;
		std::string	_name;
};

#endif
