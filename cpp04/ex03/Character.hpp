
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class Character : public ICharacter
{
	public :
		Character(std::string name);
		Character(Character &t);
		Character &operator = (const Character &t);
		virtual ~Character(void);

		virtual std::string const	&get_name(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
		void						handle_lost(void);
		void						show_inventory(void) const;
	private :
		std::string	_name;
		AMateria	*_lost;
		AMateria	*_inventory[4];
		Character(void);
};

#endif
