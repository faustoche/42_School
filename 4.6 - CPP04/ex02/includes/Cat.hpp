#ifndef		CAT_HPP
# define	CAT_HPP

/*-------------- INCLUDES --------------*/

#include "Animal.hpp"
#include "Brain.hpp"

/*-------------- CLASS --------------*/

class Cat : public AAnimal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat();

	virtual void	makeSound() const ;
	Brain	*haveBrain();
};

#endif