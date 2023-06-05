
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>

class MateriaSource
{
	public :
		MateriaSource(void);
		MateriaSource(MateriaSource &t);
		MateriaSource &operator = (const MateriaSource &t);
		~MateriaSource(void);
};

#endif