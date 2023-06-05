
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	public :
		AAnimal(void);
		AAnimal(AAnimal &t);
		AAnimal &operator = (const AAnimal &t);
		virtual ~AAnimal(void);

		virtual void		make_sound(void) const = 0;
		virtual std::string	get_type(void) const;
	protected :
		std::string	_type;
};

#endif
