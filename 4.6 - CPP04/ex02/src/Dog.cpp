#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

/*-------------- CONSTRUCTORS --------------*/

// Chaque DOG doit avoir son brain à la création

Dog::Dog() : AAnimal("Dog"){
	this->brain = new Brain();
	std::cout << BLUE_BRIGHT << "[DOG] " << RESET << "Constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other){
	this->brain = new Brain(*other.brain);
	std::cout << BLUE_BRIGHT << "[DOG] " << RESET << "Copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other){
		AAnimal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(){
	delete brain;
	std::cout << BLUE_BRIGHT << "[DOG] " << RESET << "Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Dog::makeSound() const {
	std::cout << "Woof Woof!" << std::endl;
}

Brain	*Dog::haveBrain(){
	return (this->brain);
}