
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &t);
		WrongAnimal(void);
		WrongAnimal &operator = (WrongAnimal &t);

		void		make_sound(void) const;
		std::string	get_type(void) const;
	protected :
		std::tring	_type;
};

#endif
