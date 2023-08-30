
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
	return (0);
}
