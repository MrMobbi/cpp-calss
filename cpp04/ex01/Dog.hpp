
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	public :
		Dog(void);
		Dog(Dog &t);
		Dog &operator = (const Dog &t);
		virtual ~Dog(void);

		void	new_idea(std::string idea) const;
		void	print_idea(int nb) const;
	private :
		Brain	*_brain;
};

#endif
