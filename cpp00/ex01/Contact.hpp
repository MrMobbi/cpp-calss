
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact 
{
	public:
		void		update_contact(std::string f_n, std::string l_n, std::string n_n, std::string p_n, std::string d_s, int id);
		std::string	get_first_name(void) const;
		std::string	get_last_name(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phone_number(void) const;
		std::string	get_darkest_secret(void) const;
		int			get_id(void) const;

//		## Constructor and Destructor ##
		Contact(void);
		Contact(std::string f_n, std::string l_n, std::string n_n, std::string p_n, std::string d_s, int id);
		~Contact(void);
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int			_id;
};

#endif
