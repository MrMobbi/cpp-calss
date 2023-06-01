
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>

class WrongCat
{
	public :
		WrongCat(void);
		WrongCat(WrongCat &t);
		WrongCat(void);
		WrongCat &operator = (WrongCat &t);
};

#endif
