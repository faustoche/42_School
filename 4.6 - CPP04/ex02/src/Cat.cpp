#include "../includes/Animal.hpp"
#include "../includes/Cat.hpp"

/*-------------- CONSTRUCTORS --------------*/

Cat::Cat() : AAnimal("Cat"){
	this->brain = new Brain();
	std::cout << TURQUOISE << "[CAT] " << RESET << "Constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other){
	this->brain = new Brain(*other.brain);
	std::cout << TURQUOISE << "[CAT] " << RESET << "Copy constructor called." << std::endl;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other){
		AAnimal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(){
	delete brain;
	std::cout << TURQUOISE << "[CAT] " << RESET << "Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Cat::makeSound() const {
	std::cout << "I am a world leader. Meow" << std::endl;
}

Brain	*Cat::haveBrain(){
	return (this->brain);
}