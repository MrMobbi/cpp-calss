
#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "include.h"

class Serializer
{
	public :
		~Serializer(void);

		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
	
	private :
		Serializer(void);
		Serializer(const Serializer &t);
		Serializer &operator = (const Serializer &t);
};

#endif
