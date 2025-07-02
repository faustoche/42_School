#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

/*-------------- CONSTRUCTORS --------------*/

/* Each dog need its own brain when created*/

Dog::Dog() : Animal("Dog"){
	this->brain = new Brain();
	std::cout << BLUE_BRIGHT << "[DOG] " << RESET << "Constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other){
	this->brain = new Brain(*other.brain);
	std::cout << BLUE_BRIGHT << "[DOG] " << RESET << "Copy constructor called." << std::endl;
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other){
		Animal::operator=(other);
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