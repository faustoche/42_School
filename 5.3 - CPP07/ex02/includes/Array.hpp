#ifndef ARRAY_HPP
#define ARRAY_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include "colors.hpp"
#include <stdexcept>
#include <ctime>
#include <cstdlib>

/*-------------- INCLUDES --------------*/

template<typename T>
class Array
{
private:
	T *_data;
	int _size;

public:
	Array();
	Array(int n);
	Array(const Array &other); // attention! faire des deep copy
	Array &operator=(const Array &other); // attention! faire des deep copy
	~Array();

	T &operator[](int index);
	const T &operator[](int index) const;
	int size() const;
};

#include "Array.tpp"

#endif