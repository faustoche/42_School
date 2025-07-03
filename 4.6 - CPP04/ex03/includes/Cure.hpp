#ifndef CURE_HPP
#define CURE_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "AMateria.hpp"

/*-------------- CLASS --------------*/

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	virtual ~Cure();

	Cure *clone() const;
	void	use(ICharacter &target);
};

#endif