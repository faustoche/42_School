#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

/*-------------- CLASS --------------*/

class MateriaSource : public IMateriaSource
{
protected:

public:
	AMateria *materia[4];

	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);
};

#endif