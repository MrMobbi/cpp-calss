
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

int	main(void)
{
	std::string									reader("2013-09-12 | 98.5987");
	std::string									key;
	std::string									value;
	std::map<std::string, int>	_map;

	std::cout << "before erase :\n" << reader << std::endl;
	reader.erase(remove_if(reader.begin(), reader.end(), ::isspace), reader.end());
	std::cout << "after erase :\n" << reader << std::endl;


	key.assign(reader, 0, 10);
	value.assign(reader.begin() + 11, reader.end());

	std::cout << "Key : [" << key << "] | Value : [" << value << "]" << std::endl;
	
	_map[key] = std::atoi(value.c_str());
	
	std::cout << std::endl;
	std::map<std::string, int>::const_iterator	x = _map.begin();
	std::cout << "Map -> [" << x->first << "] | [" << x->second << "]" << std::endl;

	std::cout << std::endl;
	std::cout << "Compare between 2 string :" << std::endl;

	std::string	needle = "2013-01-01";
	std::vector<std::string>	haystack;
	haystack.push_back("2012-10-12");
	haystack.push_back("2012-11-31");
	haystack.push_back("2012-12-03");
	std::vector<std::string>::iterator	it = haystack.begin();
	std::string	found(*it); 
	int					res = abs(needle.compare(*it));

	std::cout << "Resultat of compare : " << res << std::endl;
	for (;it != haystack.end(); it++)
	{
		std::cout << abs(needle.compare(*it)) << std::endl;
		if (abs(needle.compare(*it)) < res)
		{
				res = abs(needle.compare(*it));
				found = *it;
		}
	}

	std::cout << "Resultat of compare : " << res << std::endl;
	std::cout << "Neddle : " << needle << " | found : " << found << std::endl;
	return (0);
}
