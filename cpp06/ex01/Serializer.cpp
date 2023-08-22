
#include "Serializer.hpp"

//	### Constructor ###

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer &t) { (void) t; }

//	### Overload Operator ###

Serializer &Serializer::operator = (const Serializer &t)
{
	(void) t;
	return (*this);
}

//	### Destructor ###

Serializer::~Serializer(void) {}

//	### Member Function ###

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
