#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include "colors.hpp"

/*-------------- TEMPLATES --------------*/

/*
** Keyword template indicated that T is a generic type
** T can represents any type as long as he's compatible with operations
** Avoid code duplication
** Code is more flexible and reusable 
*/

/* Swap is switching 2 values without knowing in advance what type they will be */

template<typename T>
void swap(T &s1, T &s2)
{
	T tmp = s1;
	s1 = s2;
	s2 = tmp;
}

/* Compare the ascii value of the firsts characters */

template<typename T>
T& min(T &a, T &b)
{
	if (a < b)	
		return (a);
	else
		return (b);
}

template<typename T>
T& max(T &a, T &b)
{
	if (a > b)
		return (a);
	else
		return(b);
}

#endif