
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public :
		Cat(void);
		Cat(Cat &t);
		Cat &operator = (const Cat &t);
		virtual ~Cat(void);
		
		void	new_idea(std::string idea) const;
		void	print_idea(int nb) const;
	private :
		Brain	*_brain;
};

#endif
