
#include <string>
#include <iostream>
#include "iter.hpp"

void	plusOne(int &nb)
{
	nb++;
}

void	capitalizer(std::string &str)
{
	char *s = const_cast<char *>(str.c_str());
	for (int i = 0; s[i] != '\0'; i++)
		s[i] = std::toupper(s[i]);
	str = s;
}

void	rot13(char &c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		c += 13;
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c <= 'z'))
		c -= 13;
}

int	main(void)
{
	int			int_tab[4] = {4, 3 , 2, 1};
	std::string	str_tab[4] = {"hello", " ", "world", "!"};
	char		char_tab[4] = {'a', 'b', 'c', 'd'};

	std::cout << "Testing array of Int" << std::endl;
	::showArray(int_tab, 4);
	::iter(int_tab, 4, plusOne);
	std::cout << "After function" << std::endl;
	::showArray(int_tab, 4);

	std::cout << std::endl << "Testing array of Str" << std::endl;
	::showArray(str_tab, 4.0);
	::iter(str_tab, 4.0, capitalizer);
	std::cout << "After function" << std::endl;
	::showArray(str_tab, 4.0);

	std::cout << std::endl << "Testing array of Char" << std::endl;
	::showArray(char_tab, 4.0f);
	::iter(char_tab, 4.0f, rot13);
	std::cout << "After function" << std::endl;
	::showArray(char_tab, 4.0f);
	return (0);
}
