#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

/*-------------- INCLUDES --------------*/

#include "MutantStack.hpp"

/*-------------- CONSTRUCTORS --------------*/

template<typename T>
MutantStack<T>::MutantStack(){}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other) : std::stack<T>(other){}

template<typename T>
MutantStack<T>::~MutantStack(){}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other){
	std::stack<T>::operator=(other);
	return (*this);
}

/*-------------- FUNCTIONS --------------*/

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(){
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(){
	return (this->c.end());
}

#endif