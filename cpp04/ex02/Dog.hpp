
#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public :
		Dog(void);
		Dog(Dog &t);
		Dog &operator = (const Dog &t);
		virtual ~Dog(void);

		void	new_idea(std::string idea) const;
		void	print_idea(int nb) const;
		virtual void	make_sound(void) const;
	private :
		Brain	*_brain;
};

#endif
