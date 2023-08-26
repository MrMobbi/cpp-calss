
#include <vector>
#include <algorithm>
#include <iostream>
#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	test;
	MutantStack<int>	truc(test);
	MutantStack<int>	truc2;

	truc2 = test;
	test.push(5);
	std::cout << test.top() << std::endl;
	return (0);
}
