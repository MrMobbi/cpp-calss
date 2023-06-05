
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public :
		AMateria(void);
		AMateria(const std::string &type);
		AMateria(const AMateria &t);
		AMateria &operator = (const AMateria &t);
		virtual ~AMateria(void);

		std::string const	&get_type(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);
	protected :
		std::string	_type;
};

#endif
