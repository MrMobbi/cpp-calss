
#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

# include <iostream>
# include <cctype>
# include "value.h"
# include "Error.hpp"

class Error;

class ScalarConvert
{
	public :
		~ScalarConvert(void);

		static void		pars(const std::string str);
		static char		toChar(const std::string str);
		static int		toInt(const std::string str);
		static float	toFloat(const std::string str);
		static double	toDouble(const std::string str);
		static void		convert(const std::string str);
	private :
		ScalarConvert(void);
		ScalarConvert(const ScalarConvert &t);
		ScalarConvert &operator = (const ScalarConvert &t);
};

#endif
