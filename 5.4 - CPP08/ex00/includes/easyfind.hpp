#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "colors.hpp"
#include <list>
#include <climits>


/*-------------- TEMPLATE --------------*/

/*
** Containers help us to store and organize element. Every container is generic (as a template) and can store any type
** 3 types of containers : 
** - vector: dynamic array, access with index
** - list : double-chained list
** - deque : double-ended queue
** Template T is helping easyfind to automatically different types of containers 
** Iterator is used to access and iterate through elements of data structure
*/

template<typename T>
typename T::iterator easyfind(T &container, int value);

class ValueNotFoundException : public std::exception
{
public:
	virtual const char *what() const throw(){
		return ("Value not found");
	}
};

#endif