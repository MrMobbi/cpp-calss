
#include "BitcoinExchange.hpp"

//	### Constructor ###

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string data, std::string wallet)
{
	std::ifstream	ifs_data(data.c_str());
	std::ifstream	ifs_wallet(wallet.c_str());

	if (!ifs_data.is_open() || !ifs_wallet.is_open())
		throw (FileNotValidException());
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &t)
{
	(void) t;
}

//	### Overload Operator ###

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &t)
{
	(void) t;
	return (*this);
}

//	### Destructor ###

BitcoinExchange::~BitcoinExchange(void) {}

//	### Member Function ###


//	### Exception member ###

const char	*BitcoinExchange::FileNotValidException::what(void) const throw()
{
	return ("File is not vaild");
}
