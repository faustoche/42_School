#ifndef EASYFIND_HPP
#define EASYFIND_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "colors.hpp"
#include <list>
#include <climits>


/*-------------- TEMPLATE --------------*/

/*
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