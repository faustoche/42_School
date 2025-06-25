#ifndef		DOG_HPP
# define	DOG_HPP

/*-------------- INCLUDES --------------*/

#include "Animal.hpp"

/*-------------- CLASSES --------------*/

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	virtual void	makeSound() const ;
};

#endif