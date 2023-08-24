
#include <iostream>
#include "Array.hpp"

#define	VALUE 5

int	main(void)
{
	Array	<float>test(VALUE);

	for (int i = 0; i < VALUE; i++)
		test[i] = i;

	Array	<float>truc(test);
	Array	<float>truc2;

	test[1] = 1000;
	truc2 = test;
	test[2] = 2000;

	std::cout << "Printing test" << std::endl;
	for (int i = 0; i < VALUE; i++)
		std::cout << test[i] << std::endl;

	std::cout << "Printing truc" << std::endl;
	for (int i = 0; i < VALUE; i++)
		std::cout << truc[i] << std::endl;;

	std::cout << "Printing truc2" << std::endl;
	for (int i = 0; i < VALUE; i++)
		std::cout << truc2[i] << std::endl;

	try
	{
		std::cout << test[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << test[VALUE] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
