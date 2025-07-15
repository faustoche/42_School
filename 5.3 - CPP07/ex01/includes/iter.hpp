#ifndef ITER_HPP
#define ITER_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <stdlib.h>
#include "colors.hpp"

/*-------------- TEMPLATE --------------*/

template<typename T>
void	print_tab(T &tab){
	std::cout << tab << " ";
};

template<typename T>
void	increment(T &value){
	value++;
}

/* Giving T as the type of element in the array and Func as the function to pass as a parameters */

template<typename T, typename Func>
void iter(T *array, int len, Func f){
	if (!array)
		return ;
	for (int i = 0; i < len; i++)
		f(array[i]);
};

#endif