#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "colors.hpp"

/*-------------- CLASSES --------------*/

/*
** We call an abstract class if it contains at least one pure virtual methode
** In order to be a virtual methode, we add = 0 at the end
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

	virtual void	makeSound() const = 0;
	std::string getType(void) const;
}; 

#endif