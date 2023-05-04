
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook 
{
	public:
		void	ft_create_user(void);

//		## Constructor and Destructor ##
		PhoneBook(void);
		~PhoneBook(void);
	private:
		Contact	*user[8];
};
#endif
