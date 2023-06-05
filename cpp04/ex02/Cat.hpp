
#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
	public :
		Cat(void);
		Cat(Cat &t);
		Cat &operator = (const Cat &t);
		virtual ~Cat(void);
		
		void	new_idea(std::string idea) const;
		void	print_idea(int nb) const;
		virtual	void	make_sound(void) const;
	private :
		Brain	*_brain;
};

#endif
