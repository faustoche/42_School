#ifndef ARRAY_HPP
#define ARRAY_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include "colors.hpp"

/*-------------- INCLUDES --------------*/

template<typename T>
class Array
{
private:


public:
	Array();
	Array(unsigned int n); // create an array of n element initialized by default
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	Array *size();
};

/*
You MUST use the operator new[] to allocate memory. Preventive allocation (allocating memory in advance) is forbidden. Your program must never access nonallocated memory.
• Elements can be accessed through the subscript operator: [ ].
• When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
*/

#endif