
#include "BitcoinExchange.hpp"

//	### Constructor ###

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(std::string data, std::string wallet)
{
	std::ifstream	ifs_data(data.c_str());
	std::ifstream	ifs_wallet(wallet.c_str());

	if (!ifs_data.is_open() || !ifs_wallet.is_open())
		throw (FileNotValidException());
	this->_data = assignMap(ifs_data, ',');
	this->_wallet = assignMap(ifs_wallet, '|');
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &t) : \
	_data(t._data), _wallet(t._wallet) {}

//	### Overload Operator ###

BitcoinExchange &BitcoinExchange::operator = (const BitcoinExchange &t)
{
	this->_data.clear();
	this->_wallet.clear();
	this->_data = t._data;
	this->_wallet = t._wallet;
	return (*this);
}

//	### Destructor ###

BitcoinExchange::~BitcoinExchange(void) {}

//	### Member Function ###

std::map<std::string, std::string>	BitcoinExchange::assignMap(std::ifstream &ifs, char c) const
{
	std::string	read;
	std::string	key;
	std::string	value;
	std::map<std::string, std::string>	mymap;

	while (std::getline(ifs, read))
	{
		if (read.size() != 0)
		{
			read.erase(remove_if(read.begin(), read.end(), ::isspace), read.end());
			read.find(c) < read.size() ? key.assign(read, 0, read.find(c)) :\
				key.assign(read, 0, read.size());
			read.find(c) < read.size() ? value.assign(read, read.find(c) + 1, read.size() - 1) : \
				value = "wrong";
			mymap[key] = value;
		}
	}
	return (mymap);
}

std::map<std::string, std::string>	BitcoinExchange::getData(void) const
{
	return (this->_data);
}

std::map<std::string, std::string>	BitcoinExchange::getWallet(void) const
{
	return (this->_wallet);
}

//	### Exception member ###

const char	*BitcoinExchange::FileNotValidException::what(void) const throw()
{
	return ("File is not vaild");
}
