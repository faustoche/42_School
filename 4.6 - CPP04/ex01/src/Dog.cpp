#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"

/*-------------- CONSTRUCTORS --------------*/

Dog::Dog() : Animal("Dog"){
	std::cout << "[DOG] Constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other.type){
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
	std::cout << "Woof Woof!" << std::endl;
}

Brain	*Dog::haveBrain(){
	return (this->brain);
}