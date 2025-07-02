#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/*-------------- CLASS --------------*/

/*
** LearnMateria: copy parameters's materia et keep it in order to clone it later
** CreateMateria: return a new materia. It's a copy of the one learned before by materiasource. 
**				  the type is the same as the one passed in parameters. Return 0 if type is unknown.
*/

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif