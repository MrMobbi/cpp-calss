
#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Ice : public AMateria
{
	public :
		Ice(void);
		Ice(const Ice &t);
		Ice &operator = (const Ice &t);
		virtual ~Ice(void);

		virtual	AMateria	*clone(void) const;
		virtual void		use(ICharacter &target);
};

#endif
