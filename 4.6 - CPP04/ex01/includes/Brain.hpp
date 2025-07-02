#ifndef BRAIN_HPP
# define BRAIN_HPP

/*-------------- INCLUDES --------------*/

#include <string>
#include <iostream>

/*-------------- CLASS --------------*/

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain (const Brain &other);
	Brain &operator=(const Brain &other);
	~Brain();

	std::string	*getIdeas();
	void	setIdeas(std::string *newIdeas);
	void	setOneIdea(std::string idea, int i);
};

#endif