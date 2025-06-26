#ifndef BRAIN_HPP
# define BRAIN_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- CLASSES --------------*/

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain (const Brain &other);
	Brain &operator=(const Brain &other);
	virtual ~Brain();
};

#endif