
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	public :
		WrongAnimal(void);
		WrongAnimal(WrongAnimal &t);
		WrongAnimal &operator = (const WrongAnimal &t);
		virtual ~WrongAnimal(void);

		void		make_sound(void) const;
		std::string	get_type(void) const;
	protected :
		std::string	_type;
};

#endif
