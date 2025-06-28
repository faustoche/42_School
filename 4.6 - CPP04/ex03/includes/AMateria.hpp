#ifndef MATERIA_HPP
#define MATERIA_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- CLASSES --------------*/

/* AMateria = classe abstraite */

class ICharacter;

class AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();

	std::string const &getType() const; // returns materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif