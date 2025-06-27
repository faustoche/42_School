#include "../includes/Animal.hpp"
#include "../includes/Brain.hpp"

/*-------------- CONSTRUCTORS --------------*/

Brain::Brain(){
	std::cout << "[Brain] Constructor called." << std::endl;
}

Brain::Brain(const Brain &other){
	*this = other;
}

Brain &Brain::operator=(const Brain &other){
	if (this != &other){
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(){
	std::cout << "[Brain] Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

std::string	*Brain::getIdeas(){
	std::string	*p_ideas = this->ideas;
	return (p_ideas);
}

void	Brain::setIdeas(std::string *newIdeas){
	for (int i = 0; i < 100; i++)
		this->ideas[i] = newIdeas[i];
}

void	Brain::setOneIdea(std::string idea, int i){
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
}