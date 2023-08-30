
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int	main(void)
{
	Span	v1(10000);
	int		r = 1000;

	srand(time(NULL));
	int	rand = std::rand();
	try
	{
		for(int i = 0; i < 5 ; i++)
		{
			rand = std::rand();
			v1.addNumber(rand % r);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	
	
	Span	v2(v1);

	Span	v3(5);
	v3 = v1;

	try
	{
		std::vector<int>	tail;
		for(int i = 0; i < 5 ; i++)
		{
			rand = std::rand();
			tail.push_back(rand & r);
		}

		v1.insertNumber(tail.begin(), tail.end());
		std::cout << "displaying info of original :" << std::endl;
		v1.displayCapacity();
		v1.displayElements();
	
		std::cout << "displaying info of copy constructor :" << std::endl;
		v2.displayCapacity();
		v2.displayElements();
		std::cout << "displaying info of overload copy :" << std::endl;
		v3.displayCapacity();
		v3.displayElements();

		std::cout << std::endl;
		std::cout << "Shortest v1 [" << v1.shortestSpan() << "]" << std::endl;
		std::cout << "Shortest v2 [" << v2.shortestSpan() << "]" << std::endl;
		std::cout << "Shortest v3 [" << v3.shortestSpan() << "]" << std::endl;
	
		std::cout << std::endl;
		std::cout << "Longest v1 [" << v1.longestSpan() << "]" << std::endl;
		std::cout << "Longest v2 [" << v2.longestSpan() << "]" << std::endl;
		std::cout << "Longest v3 [" << v3.longestSpan() << "]" << std::endl;

		for(int i = 0; i < 9990 ; i++)
		{
			rand = std::rand();
			v1.addNumber(rand);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}	

	return (0);	
}
