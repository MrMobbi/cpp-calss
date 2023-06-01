
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(Cat &t);
		Cat &operator = (const Cat &t);
		virtual ~Cat(void);
};

#endif
