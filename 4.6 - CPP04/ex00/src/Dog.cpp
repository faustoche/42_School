#include "Animal.hpp"

/*-------------- CONSTRUCTORS --------------*/

Dog::Dog(){
	this->type = "Dog";
	std::cout << "[DOG] Constructor called." << std::endl;
}

Dog::Dog(const Dog &other){
	*this = other;
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog(){
	std::cout << "[DOG] Destructor called." << std::endl;
}

/*-------------- FUNCTIONS --------------*/

void	Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}