#! /bin/bash

touch $1.cpp $1.hpp



echo -n "
#ifndef " > $1.hpp
echo -n "$1" | tr '[:lower:]' '[:upper:]' >> $1.hpp
echo -n "_HPP
# define " >> $1.hpp
echo -n "$1" | tr '[:lower:]' '[:upper:]' >> $1.hpp
echo -n "_HPP

# include <iostream>

class $1
{
	public :
		$1(void);
		$1($1 &t);
		$1(void);
		$1 &operator = ($1 &t);
};

#endif" >> $1.hpp

echo "
#include \"$1.hpp\"

//	### Constructor ###

$1::$1(void)
{
	std::cout << \"Default constructor of $1 called\" << std::endl;
}

$1::$1($1 &t)
{
	(void) t;
	std::cout << \"Copy constructor of $1 called\" << std::endl;
}

//	### Overload Operator ###

$1 &$1::operator = (const $1 &t)
{
	(void) t;
	std::cout << \"Copy assignement operator of $1 called\" << std::endl;
	return (*this);
}

//	### Destructor ###

$1::~$1(void)
{
	std::cout << \"Destructor of $1 called\" << std::endl;
}

//	### Member Function ###
" > $1.cpp
