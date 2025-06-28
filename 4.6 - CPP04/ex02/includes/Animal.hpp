#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "colors.hpp"

/*-------------- CLASSES --------------*/

/*
** Une classe devient abstraite si elle contient au moins une méthode virtuelle pure
** Pour que ça devienne une méthode virtuelle, on écrit = 0 à la fin d'une méthode virtuelle
*/

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(void);
	AAnimal(std::string type);
	AAnimal(const AAnimal &other);
	AAnimal &operator=(const AAnimal &other);
	virtual	~AAnimal();

	virtual void	makeSound() const = 0; // méthode virtuelle pure
	std::string getType(void) const;
}; 

#endif