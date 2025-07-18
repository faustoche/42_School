#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

/*-------------- INCLUDES --------------*/

#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include "colors.hpp"

/*-------------- CLASS --------------*/

/*
** std::stack is used to deal with situation where you only need access to thing in opposite of their arrival 
** We cannot go through std::stack like in an array, cause its using another container to keep its element
** But we do not have access to this other container and can't use for loop to go through
** There's a protected variable inside std::stack called 'c'
** THis variable is holding element (by default)
** We have to create a class heritating from std::stack to have access to 'c'
** As 'c' is a basic container, it has iterators to go through each elements
** In mutant class we heritate from std::stack, and we add iterators
** So we can go through the pile, what we cannot do with std::stack
*/

template<typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	iterator begin();
	iterator end();
};

#endif