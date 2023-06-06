
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(WrongCat &t);
		WrongCat &operator = (const WrongCat &t);
		virtual ~WrongCat(void);

		void		make_sound(void) const;
};

#endif
