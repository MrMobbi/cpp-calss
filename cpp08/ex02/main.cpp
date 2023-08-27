
#include <vector>
#include <algorithm>
#include <iostream>
#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int>	mutant;
	mutant.push(1);
	MutantStack<int>	mutant2(mutant);
	MutantStack<int>	mutant3;

	mutant.push(5);
	mutant.push(34);
	mutant.push(23);
	mutant.push(63);
	mutant.push(29);

	mutant3 = mutant;
	std::cout << "Testing Mutant3 :" << std::endl;
	std::cout << mutant3.top() << std::endl;
	std::cout << "Testing Mutant2 :" << std::endl;
	std::cout << mutant2.top() << std::endl;
	std::cout << "Testing Mutant :" << std::endl;
	std::cout << mutant.top() << std::endl;

	MutantStack<int>::iterator	it = mutant.begin();
	MutantStack<int>::iterator	ite = mutant.end();
	std::cout << "Going into the MutantStack by iterator :" << std::endl;
	for (;it != ite; it++)
		std::cout << *it << std::endl;
	it--;
	std::cout << "Going revrese :" << std::endl;
	for (;it != mutant.begin(); it--)
		std::cout << *it << std::endl;
	std::cout << *it << std::endl;
	return (0);
}
