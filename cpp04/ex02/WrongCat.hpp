
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
		~WrongCat(void);
};

#endif
