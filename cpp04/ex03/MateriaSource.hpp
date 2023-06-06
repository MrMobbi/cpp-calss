
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class AMateria;

class MateriaSource : public IMateriaSource
{
	public :
		MateriaSource(void);
		MateriaSource(MateriaSource &t);
		MateriaSource &operator = (const MateriaSource &t);
		virtual ~MateriaSource(void);

		virtual void		learn_materia(AMateria *m);
		virtual	AMateria	*create_materia(std::string const &type);
		void				show_stock(void) const;		
	private :
		AMateria *_stock[4];
};

#endif
