#ifndef		DOG_HPP
# define	DOG_HPP

/*-------------- INCLUDES --------------*/

#include "Animal.hpp"
#include "Brain.hpp"

/*-------------- CLASS --------------*/

class Dog : public AAnimal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog();

	virtual void	makeSound() const ;
	Brain	*haveBrain();
};

#endif