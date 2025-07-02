#include "../includes/Animal.hpp"

/*-------------- CONSTRUCTORS --------------*/

AAnimal::AAnimal() : type("Animal"){
	std::cout << GREEN << "[ANIMAL] " << RESET << " Constructor called." << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type){
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type){
}

AAnimal &AAnimal::operator=(const AAnimal &other){
	if (this != &other){
		this->type = other.type;
	}
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout << GREEN << "[ANIMAL] " << RESET << " Destructor called." << std::endl;
}

/*-------------- GETTERS --------------*/

std::string	AAnimal::getType(void) const {
	return (this->type);
}
