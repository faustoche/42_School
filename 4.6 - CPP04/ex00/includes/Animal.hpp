#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "colors.hpp"

/*-------------- CLASS --------------*/

/*
** Variable type to keep the type of animal (dog or cat)
** Using protected so heritante classes can access to the type
** 2 constructors: one without parameters, the other one to call Animal a("Dog")
** Destructor has to be virtual for polymorphism
** Getter is const because it's not changing the object, only getting it
** makeSound is virtual so we cannot redefine it in heritante classes
*/

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