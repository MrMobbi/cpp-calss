
#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cctype>
# include <cstdlib>
# include <sstream>
# include "Error.hpp"

class Error;

class ScalarConvert
{
	public :
		~ScalarConvert(void);

		static void	convert(const std::string str);
	private :
		ScalarConvert(void);
		ScalarConvert(const ScalarConvert &t);
		ScalarConvert &operator = (const ScalarConvert &t);
};

#endif
