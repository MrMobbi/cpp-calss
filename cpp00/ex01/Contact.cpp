
#include "Contact.hpp"

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

int	Contact::get_id(void) const
{
	return (this->_id);
}

Contact::Contact(void)
{
	std::cout << "Constructor of Contact with nothing called" << std::endl;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret = "";
	this->_id = 0;
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
