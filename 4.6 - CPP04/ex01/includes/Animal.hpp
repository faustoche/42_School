#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "colors.hpp"

/*-------------- CLASS --------------*/

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual	~Animal();

	std::string getType(void) const;
	virtual void	makeSound() const;
}; 

#endif