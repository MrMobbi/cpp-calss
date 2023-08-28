
#include <iostream>
#include <vector>
#include <algorithm>

int	main(void)
{

	std::vector<int>	lst;
	lst.push_back(1);
	lst.push_back(2);
	
	std::vector<int>	lst2;
	lst2.push_back(3);
	lst2.push_back(4);

	lst.insert(lst.end(), lst2.begin(), lst2.end());

	std::vector<int>::iterator	it = lst.begin();
	for (;it != lst.end(); it++)
		std::cout << "[" << *it << "]" << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << rand() << std::endl;
	return (0);
}
