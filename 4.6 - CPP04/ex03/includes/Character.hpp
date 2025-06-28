#ifndef CHARACTER_HPP
#define CHARACTER_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

/*-------------- CLASS --------------*/

class AMateria;

class Character
{
protected:
	std::string name;
	AMateria	*inventory[4];

public:
	Character();
	Character(const std::string name);
	Character(const Character &other);
	Character &operator=(const Character &other);
	virtual ~Character();

	const	std::string	&getName() const;
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip (int idx);
	void use(int idx, ICharacter &target);
};

#endif