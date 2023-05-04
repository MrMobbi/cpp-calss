
#include "Contact.hpp"

void	Contact::ft_get_contact_info(void) const
{
	std::cout << this->_first_name << std::endl;
	std::cout << this->_last_name << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << this->_phone_number << std::endl;
	std::cout << this->_darkest_secret << std::endl;
	std::cout << this->_id << std::endl;
}

Contact::Contact(void)
{
	std::cout << "Constructor of Contact with nothing called" << std::endl;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	return ;
}

Contact::Contact(std::string f_n, std::string l_n, std::string n_n, std::string p_n, std::string d_s, int id)
	:_first_name(f_n), _last_name(l_n), _nickname(n_n), _phone_number(p_n), _darkest_secret(d_s), _id(id)
{
	std::cout << "Constructor of Contact with infos called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Destructor of Contact called" << std::endl;
	return ;
}
