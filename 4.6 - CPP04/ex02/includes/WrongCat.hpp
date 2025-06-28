#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP

/*-------------- CLASSES --------------*/

#include "WrongAnimal.hpp"

/*-------------- CLASSES --------------*/

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	virtual ~WrongCat();

	virtual void	makeSound() const ;
};

#endif