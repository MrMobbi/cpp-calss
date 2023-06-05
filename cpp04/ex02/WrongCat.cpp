
#include "WrongCat.hpp"

//	### Constructor ###

WrongCat::WrongCat(void)
{
	WrongAnimal::_type = "WrongCat";
	std::cout << "Constructor of WrongCat have been called" << std::endl;	
}

WrongCat::WrongCat(WrongCat &t)
{
	WrongAnimal::_type = t._type;
	std::cout << "Copy Constructor of WrongCat have been called" << std::endl;	
}

//	### Overload Operator ###

WrongCat &WrongCat::operator = (const WrongCat &t)
{
	this->_type = t._type;
	std::cout << "Copy assignement operator of WrongCat called" << std::endl;
	return (*this);
}

//	### Destructor ###

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor of WrongCat called" << std::endl;
}
