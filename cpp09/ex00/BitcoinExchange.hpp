
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <vector>
# include <string>
# include <cctype>
# include <fstream>
# include <algorithm>

class BitcoinExchange
{
	public :
		BitcoinExchange(std::string data, std::string wallet);
		BitcoinExchange(const BitcoinExchange &t);
		BitcoinExchange &operator = (const BitcoinExchange &t);
		~BitcoinExchange(void);

		std::map<std::string, std::string>	assignMap(std::ifstream &ifs) const;
		std::map<std::string, std::string>	getData(void) const;
		std::map<std::string, std::string>	getWallet(void) const;

		class FileNotValidException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
	private :
		BitcoinExchange(void);
		std::map<std::string, std::string>	_data;
		std::map<std::string, std::string>	_wallet;
};

#endif
