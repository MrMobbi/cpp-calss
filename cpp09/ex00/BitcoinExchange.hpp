
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>

class BitcoinExchange
{
	public :
		BitcoinExchange(std::string data, std::string wallet);
		BitcoinExchange(const BitcoinExchange &t);
		BitcoinExchange &operator = (const BitcoinExchange &t);
		~BitcoinExchange(void);

		class FileNotValidException : public std::exception
		{
			public :
				virtual const char *what() const throw();
		};
	private :
		BitcoinExchange(void);
		std::map<std::string, int>	_data;
		std::map<std::string, int>	_wallet;
};

#endif
