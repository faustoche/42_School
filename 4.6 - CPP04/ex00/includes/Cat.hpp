#ifndef		CAT_HPP
# define	CAT_HPP

/*-------------- INCLUDES --------------*/

#include "Animal.hpp"

/*-------------- CLASSES --------------*/

/* Cat is heritated from all public and protected members of animal */

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