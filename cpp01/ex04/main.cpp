
#include <iostream>
#include <fstream>
#include <string>

void	ft_replace(std::string &read, std::string find, std::string replace)
{
	size_t	pos = 0;
	
	pos = read.find(find);
	if (pos != std::string::npos)
		read.replace(pos, find.length(), replace);
	while (pos != std::string::npos)
	{
		pos = read.find(find, pos + 1);
		if (pos != std::string::npos)
			read.replace(pos, find.length(), replace);
	}
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}

	const std::string		file(av[1]);
	const std::string		find(av[2]);
	const std::string		replace(av[3]);
	std::string		read;
	std::ifstream	ifs(file);

	if (ifs.is_open())
	{
		std::ofstream	ofs(file + ".replace", std::ofstream::trunc);
		while (ifs.good())
		{
			std::getline(ifs, read);
			if (read.length() > 0)
			{
				ft_replace(read, find, replace);
				ofs << read << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Files does't exist" << std::endl;
		return (2);
	}
	ifs.close();
	return (0);
}
