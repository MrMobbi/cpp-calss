
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"

class PhoneBook 
{
	public:
		std::string	safe_getline_pb(std::string line);
		void		ft_add(int id);
		void		ft_search(void);
		void		display_contact_semi(Contact *contact) const;
		void		display_all_info(Contact *user) const;
		void		display_in_format(std::string info) const;
		void		clean_phone_book(void);

//		## Constructor and Destructor ##
		PhoneBook(void);
		~PhoneBook(void);
	private:
		Contact	*_user[8];
		int		_nbr_user;

};
#endif
