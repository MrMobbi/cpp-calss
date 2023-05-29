
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap 
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		explicit ClapTrap(ClapTrap &t);
		ClapTrap &operator = (const ClapTrap &t);
		~ClapTrap(void);

		void		attack(const std::string target);
		void		take_damage(unsigned int amount);
		void		be_repaired(unsigned int amount);
		/*
		virtual	std::string	get_name(void) const;
		virtual	int	get_hp(void) const;
		virtual	int	get_ep(void) const;
		virtual	int	get_ad(void) const;
		*/
	protected :
		std::string	_name;
		int	_hp;
		int	_ep;
		int	_ad;
};

#endif
