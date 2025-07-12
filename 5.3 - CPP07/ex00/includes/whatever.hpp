#ifndef WHATEVER_HPP
#define WHATEVER_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>

/*-------------- TEMPLATES --------------*/

template<typename T>
void swap(T &s1, T &s2){
	T tmp = s1;
	s1 = s2;
	s2 = tmp;
}

template<typename T>
T& min(T &a, T &b){
	return ((a < b) ? a : b);
}

template<typename T>
T& max(T &a, T &b){
	return ((a > b) ? a : b);
}

#endif