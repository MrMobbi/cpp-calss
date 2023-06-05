
#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class AMateria;
class ICharacter;

class Cure : public AMateria
{
	public :
		Cure(void);
		Cure(const Cure &t);
		Cure &operator = (const Cure &t);
		virtual ~Cure(void);

		virtual	AMateria	*clone(void) const;
		virtual	void		use(ICharacter &target);
};

#endif
