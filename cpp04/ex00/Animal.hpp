
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	public :
		Animal(void);
		Animal(Animal &t);
		Animal &operator = (const Animal &t);
		virtual ~Animal(void);

		virtual void		make_sound(void) const;
		std::string	get_type(void) const;
	protected :
		std::string	_type;
};

#endif
