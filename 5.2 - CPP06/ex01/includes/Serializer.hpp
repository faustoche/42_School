#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include "Data.hpp"
#include <stdint.h>
#include "colors.hpp"

/*-------------- CLASS --------------*/

class Data;

class Serializer
{
public:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();

	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};

#endif