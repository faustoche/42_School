#ifndef		CAT_HPP
# define	CAT_HPP

/*-------------- INCLUDES --------------*/

#include "Animal.hpp"

/*-------------- CLASSES --------------*/

/*
** Cat hérite de tous les membres publics et protégés d'animal
*/

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	virtual void	makeSound() const ;
};

#endif