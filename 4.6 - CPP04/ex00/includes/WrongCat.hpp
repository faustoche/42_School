#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP

/*-------------- INCLUDES --------------*/

#include "WrongAnimal.hpp"

/*-------------- CLASS --------------*/

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