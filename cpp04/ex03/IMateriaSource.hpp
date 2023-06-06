
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
	public :
		virtual 			~IMateriaSource(void) {}
		virtual void		learn_materia(AMateria *m) = 0;
		virtual AMateria	*create_materia(std::string const &type) = 0;
};

#endif
