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
** std::stack est un adaptateur de container basé sur std::deque par défaut
** Il n'expose pas les itérateurs de son container sous-jacent
** En héritant de std::stack, on peut accéder au membre protégé c qui est le container sous jacent
** Ce c est itérable
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