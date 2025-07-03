#ifndef ICE_HPP
#define ICE_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>
#include "AMateria.hpp"

/*-------------- CLASS --------------*/

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	virtual ~Ice();

	Ice	*clone() const;
	void	use(ICharacter &target);
};

#endif