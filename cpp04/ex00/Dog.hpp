
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(Dog &t);
		Dog &operator = (const Dog &t);
		virtual ~Dog(void);

		virtual void		make_sound(void) const;
};

#endif
