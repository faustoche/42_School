#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- CLASS --------------*/

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal &other);
	virtual	~WrongAnimal();
	WrongAnimal &operator=(const WrongAnimal &other);

	std::string getType() const;
	void	makeSound(void) const;
};

#endif