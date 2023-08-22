
#include <iostream>
#include "include.h"
#include "Serializer.hpp"

int	main(void)
{
	Data *test = new(Data);

	test->x = 123;
	std::cout << test << " | " << test->x << std::endl;
	uintptr_t seri = Serializer::serialize(test);
	std::cout << seri << std::endl;
	Data *test2 = Serializer::deserialize(seri);
	std::cout << test2 << " | " << test2->x << std::endl;
	delete(test);
	return (0);
}
