
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public :
		Brain(void);
		Brain(Brain &t);
		Brain &operator = (const Brain &t);
		~Brain(void);

		void		add_idea(std::string idea);
		std::string	get_idea(int nb) const; 
		int			get_nb_idea(void) const;
	private :
		std::string	_idea[100];
		int			_nb_idea;
};

#endif
