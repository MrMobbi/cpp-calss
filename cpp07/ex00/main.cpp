
#include <iostream>
#include <string>
#include "template.h"

class Data {
	public :
		Data(int value, std::string s) : _value(value), _s(s) {};
		~Data(void) {};
		int			_value;
		std::string	_s;
};

std::ostream &operator<<(std::ostream &o, const Data &t)
{
	o << t._s << ", " << t._value;
	return (o);
}

int	main(void)
{
	int	a = 1;
	int	b = 2;

	std::string s1 = "Hello";
	std::string s2 = "World!";

	Data	d1(1000, "d1");
	Data	d2(1, "d2");

	std::cout << std::endl << "Testing for 2 int :" << std::endl;
	std::cout << "a [" << a << "] | b [" << b << "]" << std::endl;
	std::cout << "min is : [" << ::min<int>(a, b) << "]" << std::endl;
	std::cout << "max is : [" << ::max<int>(a, b) << "]" << std::endl;
	::swap<int>(a, b);
	std::cout << "a [" << a << "] | b [" << b << "]" << std::endl;

	std::cout << std::endl << "Testing for 2 string :" << std::endl;
	std::cout << "s1 [" << s1 << "] | s2 [" << s2 << "]" << std::endl;
	std::cout << "min is : [" << ::min<std::string>(s1, s2) << "]" << std::endl;
	std::cout << "max is : [" << ::max<std::string>(s1, s2) << "]" << std::endl;
	::swap<std::string>(s1, s2);
	std::cout << "s1 [" << s1 << "] | s2 [" << s2 << "]" << std::endl;

	std::cout << std::endl << "Testing for 2 class :" << std::endl;
	std::cout << "d1 [" << d1 << "] | d2 [" << d2 << std::endl;
	::swap<Data>(d1, d2);
	std::cout << "d1 [" << d1 << "] | d2 [" << d2 << "]" << std::endl;


	return (0);
}
