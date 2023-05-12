
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	public:
		const std::string	&get_type(void) const;
		void		set_type(std::string new_type);
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
	private:
		std::string	_type;	
};

#endif
