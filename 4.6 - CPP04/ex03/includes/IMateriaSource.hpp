#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/*-------------- CLASS --------------*/

/*
** LearnMAteria: copie la materia passé en parametre et la stocke en memoire afin de la cloner plus tard
** createMateria : retourne une nouvelle materia. C'est une copie de celle apprise précédemment par la materiasource
** 		et dont le type est le meme que celui passé en parametre. Retourne 0 si le type est inconnu
**
*/

class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif