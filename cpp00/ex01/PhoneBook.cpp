
#include "PhoneBook.hpp"

std::string	PhoneBook::safe_getline_pb(std::string line)
{
	std::string	tmp;

	while (1)
	{
		std::cout << line;
		std::getline(std::cin, tmp);
		if (std::cin.fail() == true)
		{
			std::cout << std::endl << "Error of the input, closing program!" << std::endl;
			exit(0);
		}
		else if (tmp.length() == 0)
			std::cout << std::endl << "Field can't be blank!!" << std::endl;
		else if (tmp.length() > 0)
			break ;
	}
	return (tmp);
}

void	PhoneBook::ft_add(int id)
{
	std::string	f_n;
	std::string	l_n;
	std::string	n_n;
	std::string	p_n;
	std::string	d_s;
	
	if (id > 7)
		delete this->_user[id % 8];
	std::cout << "Creating Contact number [" << id % 8 + 1 << "]" << std::endl;
	f_n = PhoneBook::safe_getline_pb("Enter First Name : ");
	l_n = PhoneBook::safe_getline_pb("Enter Last Name : ");
	n_n = PhoneBook::safe_getline_pb("Enter Nickname : ");
	p_n = PhoneBook::safe_getline_pb("Enter Phone Number : ");
	d_s = PhoneBook::safe_getline_pb("Enter Darkest Secret : ");
	
	this->_user[id % 8] = new Contact(f_n, l_n, n_n, p_n, d_s, id % 8 + 1);
	this->_nbr_user++;
}

void	PhoneBook::ft_search(void)
{
	std::string	prompt;
	int			index;

	for (int i = 0; i < 8 && i < this->_nbr_user; i++)
		this->display_contact_semi(this->_user[i]);
	std::cout << "Which contact you want to see ?" << std::endl;
	std::cout << "Type a number between 1 and 8 or none if you don't." << std::endl;
	while (1)
	{
		prompt = PhoneBook::safe_getline_pb("Index = ");
		index = std::atoi(prompt.c_str());
		if (index > 0 && index < 9)
		{
			if (index > this->_nbr_user)
				std::cout << "Sorry this conctact does not exist." << std::endl;
			else
			{
				this->display_all_info(this->_user[index - 1]);
				break ;
			}
		}
		else if (prompt == "none")
			break ;
		else
			std::cout << "Please enter a number between 1 and 8 or none." << std::endl;
	}
	std::cout << std::endl << "Back in the the main Menu ->" << std::endl;
}

void	PhoneBook::display_contact_semi(Contact *user) const
{
	std::cout << "[" << user->get_id();
	std::cout << "]|[";
	this->display_in_format(user->get_first_name());
	std::cout << "]|[";
	this->display_in_format(user->get_last_name());
	std::cout << "]|[";
	this->display_in_format(user->get_nickname());
	std::cout << "]" << std::endl; 
}

void	PhoneBook::display_all_info(Contact *user) const
{
	std::cout << std::endl << "Info of Contact Number [" << user->get_id() << "]" << std::endl;
	std::cout << "First Name : " << user->get_first_name() << std::endl;
	std::cout << "Last Name : " << user->get_last_name() << std::endl;
	std::cout << "Nickname : " << user->get_nickname() << std::endl;
	std::cout << "Phone Number : " << user->get_phone_number() << std::endl;
	std::cout << "Darkest Secret : " << user->get_darkest_secret() << std::endl;
}

void	PhoneBook::display_in_format(std::string info) const
{
	char	*str = const_cast<char *>(info.c_str());
	int		size = std::strlen(str);
	int		i = 0;

	if (size < 10)
	{
		while (i < size)
			std::cout << str[i++];
		while (i++ < 10)
			std::cout << " ";
	}
	else if (size == 10)
	{
		while (i < 10)
			std::cout << str[i++];
	}
	else
	{
		while (i < 9)
			std::cout << str[i++];
		std::cout << ".";
	}
}

void	PhoneBook::clean_phone_book(void)
{
	for (int i = 0; i < 8 && i < this->_nbr_user; i++)
		delete this->_user[i];
}

PhoneBook::PhoneBook(void)
{
	std::cout << "Constructor of PhoneBook called" << std::endl;
	this->_nbr_user = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "Destructor of PhoneBook called" << std::endl;
	return ;
}
